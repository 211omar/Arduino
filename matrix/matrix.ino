int Cat [8][8] = {
{0,0,0,0,0,0,0,0},
{0,1,1,0,0,1,1,0},
{1,0,0,0,1,0,0,0},
{1,0,0,0,1,0,0,0},
{1,0,0,0,1,0,0,0},
{1,0,0,0,1,0,0,0},
{1,0,0,0,1,0,0,0},
{1,0,0,0,1,0,0,0},
};

int col1 =6;
int col2=11 ;
int col3 =10;
int col4 =3;
int col5 =A3;
int col6 =4;
int col7 =8;
int col8 =9;

int row1 = 2;
int row2 = 7;
int row3 =A5 ;
int row4 =5 ;
int row5 =13 ;
int row6 = A4;
int row7 =12 ;
int row8 =A2 ;



void setup() {
  // put your setup code here, to run once:
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  pinMode(row4, OUTPUT);
  pinMode(row5, OUTPUT);
  pinMode(row6, OUTPUT);
  pinMode(row7, OUTPUT);
  pinMode(row8, OUTPUT);


  pinMode(col1, OUTPUT);
  pinMode(col2, OUTPUT);
  pinMode(col3, OUTPUT);
  pinMode(col4, OUTPUT);
  pinMode(col5, OUTPUT);
  pinMode(col6, OUTPUT);
  pinMode(col7, OUTPUT);
  pinMode(col8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(row1, LOW);
  // digitalWrite(row2, LOW);
  // digitalWrite(row3, LOW);
  // digitalWrite(row4, LOW);
  // digitalWrite(row5, LOW);
  // digitalWrite(row6, LOW); //3
  // digitalWrite(row7, LOW);
  // digitalWrite(row8, LOW);

  // digitalWrite(col1, HIGH);
  // digitalWrite(col2, HIGH);
  // digitalWrite(col3, HIGH);
  // digitalWrite(col4, HIGH);
  // digitalWrite(col5, HIGH);
  // digitalWrite(col6, HIGH); //3
  // digitalWrite(col7, HIGH);
  // digitalWrite(col8, HIGH);

  // for (int i = 1; i < 9; i++) {
  //   SelectRow(i);
  //   for (int j = 1; j < 9; j++) {
  //     SelectColumn(j);
  //     delay(100);
  //   }
  // }


   for (int i = 1; i < 9; i++) {
      SelectRow(i+1);
      for (int j = 0; j < 8; j++)Set_Led_in_Active_row (j+1,Cat[i][j]);
      delay(20);
    }
  
}

void SelectRow(int row) {
  if (row == 1) digitalWrite(row1, LOW);
  else digitalWrite(row1, HIGH);
  if (row == 2) digitalWrite(row2, LOW);
  else digitalWrite(row2, HIGH);
  if (row == 3) digitalWrite(row3, LOW);
  else digitalWrite(row3, HIGH);
  if (row == 4) digitalWrite(row4, LOW);
  else digitalWrite(row4, HIGH);
  if (row == 5) digitalWrite(row5, LOW);
  else digitalWrite(row5, HIGH);
  if (row == 6) digitalWrite(row6, LOW);
  else digitalWrite(row6, HIGH);
  if (row == 7) digitalWrite(row7, LOW);
  else digitalWrite(row7, HIGH);
  if (row == 8) digitalWrite(row8, LOW);
  else digitalWrite(row8, HIGH);
}
void SelectColumn(int col) {
  if (col == 1) digitalWrite(col1, HIGH);
  else digitalWrite(col1, LOW);
  if (col == 2) digitalWrite(col2, HIGH);
  else digitalWrite(col2, LOW);
  if (col == 3) digitalWrite(col3, HIGH);
  else digitalWrite(col3, LOW);
  if (col == 4) digitalWrite(col4, HIGH);
  else digitalWrite(col4, LOW);
  if (col == 5) digitalWrite(col5, HIGH);
  else digitalWrite(col5, LOW);
  if (col == 6) digitalWrite(col6, HIGH);
  else digitalWrite(col6, LOW);
  if (col == 7) digitalWrite(col7, HIGH);
  else digitalWrite(col7, LOW);
  if (col == 8) digitalWrite(col8, HIGH);
  else digitalWrite(col8, LOW);
}


void Set_Led_in_Active_row (int column,int state){
  if(column==1) digitalWrite(col1, state);
  if(column==2) digitalWrite(col1, state);
  if(column==3) digitalWrite(col1, state);
  if(column==4) digitalWrite(col1, state);
  if(column==5) digitalWrite(col1, state);
  if(column==6) digitalWrite(col1, state);
  if(column==7) digitalWrite(col1, state);
  if(column==8) digitalWrite(col1, state);
}
