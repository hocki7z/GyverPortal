// почти все компоненты

#define AP_SSID ""
#define AP_PASS ""

#include <GyverPortal.h>
GyverPortal portal;

void build() {
  GP.BUILD_BEGIN(700);    // ширина колонки
  
  GP.THEME(GP_DARK);
  //GP.THEME(GP_LIGHT);

  // при ширине меньше 600 GRID отключится (блоки пойдут по вертикали)
  GP.GRID_RESPONSIVE(600);

  GP.TITLE("Desktop Dashboard Style");
  GP.HR();

  M_GRID(
    M_BLOCK_TAB(
      "Settings",
      M_BOX(GP.LABEL("Some check 1"); GP.CHECK("");   );
      M_BOX(GP.LABEL("Some check 2"); GP.CHECK("");   );
      M_BOX(GP.LABEL("Some Switch 1"); GP.SWITCH(""); );
      M_BOX(GP.LABEL("Some Switch 2"); GP.SWITCH(""); );
    );

    M_BLOCK_TAB(
      "WiFi config",
      M_BOX(GP.LABEL("SSID");     GP.TEXT("");  );
      M_BOX(GP.LABEL("Password"); GP.TEXT("");  );
      M_BOX(GP.LABEL("Host");     GP.TEXT("");  );
    );
  );

  M_GRID(
    M_BLOCK_TAB(
      "Upload",
      M_BOX(GP.LABEL("Upload settings");  GP.FILE_UPLOAD(""); );
      M_BOX(GP.LABEL("Upload photo");     GP.FILE_UPLOAD(""); );
      M_BOX(GP.LABEL("Upload data");      GP.FILE_UPLOAD(""); );
    );

    M_BLOCK_TAB(
      "Color",
      M_BOX(GP.LABEL("Color 1");  GP.SLIDER("");  );
      M_BOX(GP.LABEL("Color 2");  GP.SLIDER("");  );
      M_BOX(GP.LABEL("Color 3");  GP.SLIDER("");  );
    );
  );

  GP.BUILD_END();
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID, AP_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());

  // подключаем конструктор и запускаем
  portal.attachBuild(build);
  portal.attach(action);
  portal.start();
}

void action() {
}

void loop() {
  portal.tick();
}
