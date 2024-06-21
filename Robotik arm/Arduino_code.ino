#include <Servo.h>  //Servo kütüphanesi koda dahil edildi

Servo servo_1;    //Servo_1 isimli nesne oluşturuldu
Servo servo_2;    //Servo_2 isimli nesne oluşturuldu
Servo servo_3;    //Servo_3 isimli nesne oluşturuldu
Servo servo_4;    //Servo_4 isimli nesne oluşturuldu

void setup() {
  servo_1.attach(4);    //Servo_1 motorun sinyal pini 4 nolu arduino pinine bağlandı (alttaki servo)
  servo_2.attach(5);    //Servo_2 motorun sinyal pini 5 nolu arduino pinine bağlandı (Sağ yandaki servo)
  servo_3.attach(6);    //Servo_3 motorun sinyal pini 6 nolu arduino pinine bağlandı (Sol yandaki servo)
  servo_4.attach(7);    //Servo_4 motorun sinyal pini 7 nolu arduino pinine bağlandı (kıskaç)
  Serial.begin(9600);
}

void loop() {
  //Joysticklerin bağlı olduğu analog pinler okunup değişkenlere kaydediliyor
  int sag_sol = analogRead(A2);      
  int ileri_geri = analogRead(A3);
  int asagi_yukari = analogRead(A1);
  int kiskac = analogRead(A0);
  Serial.println(sag_sol);

  //Analog değerler map ile servo açılarına sınırlandırılıyor
  int sag_sol_aci = map(sag_sol, 0, 1023, 0,179);
  int ileri_geri_aci = map(ileri_geri, 1023, 0, 20,150);
  int asagi_yukari_aci = map(asagi_yukari, 0, 1023, 50,150);
  int kiskac_aci = map(kiskac, 0, 1023, 10,90);

  //Açı değerleri ilgili servo motora gönderiliyor
  servo_1.write (sag_sol_aci);
  servo_2.write (ileri_geri_aci);
  servo_3.write (asagi_yukari_aci);
  servo_4.write (kiskac_aci);
}
