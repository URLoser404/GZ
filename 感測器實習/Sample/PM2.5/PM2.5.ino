float GetPM25Data();    //定义PM2.5读取的函数

void setup() {    
  Serial.begin(115200);
  Serial2.begin(2400);                 //開啟串列2
  Serial.println("serial start");      
}

void loop() {
  float pm25=0;
  pm25 = GetPM25Data();   //呼叫函数  
  Serial.println(String(pm25)+"mg/m3");   //输出PM2.5的值
  delay(2000);
}

float GetPM25Data()//讀取PM2.5感測器，鮑率：2400; 檢查位元：無; 停止位元：1 位;資料位元：8; 數據包長度為7位元組
{
  int cnt,pmval,readcmd[7];
  unsigned char gdata,eFlag,rbytes=0;
  float pm25;
  cnt=0;
  eFlag =0;
  while(Serial2.available()>0) {
    gdata = Serial2.read();//保存接收字符

    if(gdata==0xAA && eFlag==0) eFlag=1;  //起始位是0xAA
    if(eFlag==1) readcmd[rbytes++]=gdata;
    cnt++;
    if(cnt>100) return 0;
    if(rbytes==7)  break; //一共7組數據
    }
    if(rbytes==0) return 0;
    if(readcmd[6]!=0xFF) return 0;   //結束位元為OxFF
      
    pmval = readcmd[1];
    pmval<<=8;  //左移8位 Vout(H)*256
    pmval+=readcmd[2];  //Vout(H)*256+Vout(L)
    pm25 = pmval*5.0/1024.0;//計算PM2.5值，：Vout=(Vout(H)*256+Vout(L))/1024*5 
    pm25/=3.5;  //係数3.5
    for (rbytes = 0; rbytes < 7;rbytes++ ){
      Serial.println(readcmd[rbytes]);   
     } 
    Serial.println();
  return pm25;
}
