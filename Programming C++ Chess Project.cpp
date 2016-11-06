# include <iostream>
# include <conio.h>
char chess[9][9],x[2],y[2],cm='n',a='1';     //the 8*8 chessboard and checkmate character are being defined.
bool ch1=false, ch2=false;
int i,j,k,z,l,m,n,o;    //these integers are used for drawing the chessboard and the inserted numbers by the players.
using namespace std;
void draw();   //the function to draw and redraw the chessboard after each move.
void play();   //the function to determine the player of each move and get the coordinates.
bool rule(int,int,int,int); //the function for the rules and determination of the man moving.
bool pawn(int,int,int,int); //the function to check the rightness of moving if the man is a pawn.
bool rook(int,int,int,int);    //the function to check the rightness of moving if the man is a rook.
bool knight(int,int,int,int);  //the function to check the rightness of moving if the man is a knight.
bool bishop(int,int,int,int);  //the function to check the rightness of moving if the man is a bishop.
bool queen(int,int,int,int);   //the function to check the rightness of moving if the man is a queen.
bool king(int,int,int,int);    //the function to check the rightness of moving if the man is a king.
bool nomanoblique(int,int,int,int);  //the functions to check whether there is a man on the way or not.
bool nomandirect(int,int,int,int);
void check();  //the function to check the check status.
void declare(char);   //the function to declare the check status.
int main()
{
    for (k=1;k<9;k++) //drawing the first line of numbers (x coordinates) and the soldiers line.
    {
    chess[8][k]=64+k;
    chess[6][k]='P';
    chess[1][k]='p';
    }
    for (k=2;k<6;k++) //drawing the empty places between two players.
    {
        for (z=1;z<9;z++)
        chess[k][z]='.';
    }
    for (z=0;z<9;z++) //drawing the second line of each player and the y coordinates.
    chess[z][0]=56-z;
    chess[8][0]=' ';
    chess[7][1]='R';
    chess[7][2]='N';
    chess[7][3]='B';
    chess[7][4]='Q';
    chess[7][5]='K';
    chess[7][6]='B';
    chess[7][7]='N';
    chess[7][8]='R';
    for (z=1;z<9;z++)
    chess[0][z]=chess[7][z]+32;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\tPlayer1 is CAPITAL LETTERS and Player2 is small letters.\n\n\t\t\tPlease maximize the window.\n\n\n\n\n";
    cout<<"Press any key to start the game.";    //giving a comment about the players.
    getch();
	while (cm =='n') //the chessboard will be drawn and the players will move their men til checkmate happens.
	{
    draw();
    play();
    check();
    }
    getch();
	return 0;
    }
        void draw() //the draw function is defined as clearing the screen then drawing the chessboard after the last move.
    {
        system("cls");
        cout<<endl<<endl<<endl;
    for (i=0;i<9;i++)
    {
        for (j=0;j<9;j++)
        cout<<chess[i][j]<<"\t";
        cout<<endl<<endl<<endl<<endl<<endl;
    }
    cout<<endl<<endl;
    }
void play()  //the play function is defined as changing the players after each move, getting the coordinates and moving men.
{
    cout<<"Player" <<a<<":Move your man>";
    cin>>x>>y;
    m=x[0]-64;
    l=56-x[1];
    o=y[0]-64;
    n=56-y[1];
    if (m!=0 && o!=0 && l!=8 && n!=8 && rule(l,m,n,o)==true)
    {
    chess[n][o]=chess[l][m]; //to move and replace.
    chess[l][m]='.';
	a = a=='1' ? '2' : '1'; //to change the name of the players.
    }
    else
    cout<<"\a";
}
bool rule(int l, int m, int n, int o)
{
if ((a=='1' && chess[n][o]!='P' && chess[n][o]!='R' && chess[n][o]!='N' && chess[n][o]!='B' && chess[n][o]!='Q' \
&& chess[n][o]!='K' && chess[n][o]!='k' && (chess[l][m]=='P' || chess[l][m]=='R' || chess[l][m]=='N' || chess[l][m]=='B' \
|| chess[l][m]=='Q' || chess[l][m]=='K')) || (a=='2' && chess[n][o]!='p' && chess[n][o]!='r' && chess[n][o]!='n' \
&& chess[n][o]!='b' && chess[n][o]!='q' && chess[n][o]!='k' && chess[n][o]!='K' && (chess[l][m]=='p' || chess[l][m]=='r' \
|| chess[l][m]=='n' || chess[l][m]=='b' || chess[l][m]=='q' || chess[l][m]=='k'))){
//none of the players can kill their own men, they cant replace the king and they can just move their own men.
    switch (chess[l][m]){
    case 'P':
    return pawn(l,m,n,o); break;
    case 'p':
    return pawn(l,m,n,o); break;
    case 'R':
    return rook(l,m,n,o); break;
    case 'r':
    return rook(l,m,n,o); break;
    case 'N':
    return knight(l,m,n,o); break;   
    case 'n':
    return knight(l,m,n,o); break;
    case 'B':
    return bishop(l,m,n,o); break;
    case 'b':
    return bishop(l,m,n,o); break;
    case 'Q':
    return queen(l,m,n,o); break;
    case 'q':
    return queen(l,m,n,o); break;
    case 'K':
    return king(l,m,n,o); break;
    case 'k':
    return king(l,m,n,o); break;
//rules will be checked for each man in its own function and the answer will go to the move function.
}}
}
bool pawn(int l, int m, int n, int o)
{
//the pawn will move 1 or 2 squares to the empty area or just one square to kill the other side's men.
    switch (chess[l][m]){
    case 'p':{
if (chess[n][o]=='.'){ 
if (o==m && ((n==3 && l==1 && chess[2][o]=='.') || n==l+1))
return true;}
else{
if (n==l+1 && (o==m+1 || o==m-1))
return true;} break;}
    case 'P':{
if (chess[n][o]=='.'){
if (o==m && ((n==4 && l==6 && chess[5][o]=='.') || n==l-1))
return true;}
else{
if (n==l-1 && (o==m+1 || o==m-1))
return true;} break;}
}
}
bool rook(int l,int m, int n, int o)
{
//the rook can just move in the column or the row without changing the other one.
if ((l==n || m==o) && nomandirect(l,m,n,o)!=false)
return true;
}
bool knight(int l, int m, int n, int o)
{
//the knight can move in L shaped area moving 2 squares one way and 1 square the other.
if ((abs(o-m)==1 && abs(l-n)==2) || (abs(o-m)==2 && abs(l-n)==1))
return true;
}
bool bishop(int l, int m, int n, int o)
{
//the bishop will move oblique.
     if (abs(o-m)==abs(n-l) && nomanoblique(l,m,n,o)!=false)
     return true;
}
bool queen(int l,int m, int n, int o)
{
//the queen moves oblique or direct.
     if (((l==n || m==o) && nomandirect(l,m,n,o)!=false) || (abs(o-m)==abs(n-l) && nomanoblique(l,m,n,o)!=false))
     return true;
}
bool king(int l, int m, int n, int o)
{
//the king can move to every square near the first square.
     if (chess[n][o]=='.' && ((n==l && abs(o-m)==1) || (m==o && abs(n-l)==1) || (abs(o-m)==1 && abs(n-l)==1)))
     return true;
}
bool nomanoblique(int l,int m,int n,int o)
{
//if there is a man on the way and oblique the function will return false and the man wont move.
     if (n>l && o>m){
     for (i=1;i<o-m;i++){
     if (chess[l+i][m+i]!='.')
     return false;}}
     else if (n>l && o<m){
     for (i=1;i<m-o;i++){
     if (chess[l+i][m-i]!='.')
     return false;}}
     else if (n<l && o<m){
     for (i=1;i<m-o;i++){
     if (chess[l-i][m-i]!='.')
     return false;}}
     else if (n<l && o>m){
     for (i=1;i<o-m;i++){
     if (chess[l-i][m+i]!='.')
     return false;}}
}
bool nomandirect(int l,int m,int n,int o)
{
//if there is a man on the way and direct the function will return false and the man wont move.
     if (l<n && m==o){
     for (i=1;i<n-l;i++){
     if (chess[l+i][m]!='.')
     return false;}}
     else if (l>n && m==o){
     for (i=1;i<l-n;i++){
     if (chess[n+i][m]!='.')
     return false;}}
     else if (l==n && m>o){
     for (i=1;i<m-o;i++){
     if (chess[l][o+i]!='.')
     return false;}}
     else if (l==n && m<o){
     for (i=1;i<o-m;i++){
     if (chess[l][m+i]!='.')
     return false;}}
}
void check()
{
     int c1,c2,c3,c4;
     for (int a1=0;a1<8;a1++){
         for (int a2=1;a2<9;a2++){
             if (chess[a1][a2]=='k'){
             c1=a1;
             c2=a2;
             break;}}}
     for (int a3=0;a3<8;a3++){
         for (int a4=1;a4<9;a4++){
             if (chess[a3][a4]=='K'){
             c3=a3;
             c4=a4;
             break;}}}
     for (int i=0;i<8;i++){
         for (int j=1;j<9;j++){
             switch (chess[i][j]){
                    case 'P':{
                         if (i==c1+1 && (c2==j+1 || c2==j-1)){
                         declare('2');
                         break;}break;}
                    case 'p':{
                         if (i==c3-1 && (c4==j+1 || c4==j-1)){
                         declare('1');
                         break;}break;}
                    case 'R':{
                         if ((i==c1 || j==c2) && nomandirect(i,j,c1,c2)!=false){
                         declare('2');
                         break;}break;}
                    case 'r':{
                         if ((i==c3 || j==c4) && nomandirect(i,j,c3,c4)!=false){
                         declare('1');
                         break;}break;}
                    case 'N':{
                         if ((abs(c2-j)==1 && abs(c1-i)==2) || (abs(c2-j)==2 && abs(c1-i)==1)){
                         declare('2');
                         break;}break;}
                    case 'n':{
                         if ((abs(c4-j)==1 && abs(c3-i)==2) || (abs(c4-j)==2 && abs(c3-i)==1)){
                         declare('1');
                         break;}break;}
                    case 'B':{
                         if (abs(c2-j)==abs(c1-i) && nomanoblique(i,j,c1,c2)!=false){
                         declare('2');
                         break;}break;}
                    case 'b':{
                         if (abs(c4-j)==abs(c3-i) && nomanoblique(i,j,c3,c4)!=false){
                         declare('1');
                         break;}break;}
                    case 'Q':{
                         if (((i==c1 || j==c2) && nomandirect(i,j,c1,c2)!=false) || (abs(c2-j)==abs(c1-i) && nomanoblique(i,j,c1,c2)!=false)){
                         declare('2');
                         break;}break;}
                    case 'q':{
                         if (((i==c3 || j==c4) && nomandirect(i,j,c3,c4)!=false) || (abs(c4-j)==abs(c3-i) && nomanoblique(i,j,c3,c4)!=false)){
                         declare('1');
                         break;}break;}
                         }}}
                         //the places of men are found and then the check status is checked.
}
void declare(char pl)
{
     //the check status is declared for each player, separately.
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLAYER "<<pl<<" : CHECK !";
    getch();
    if (pl=='1')
    ch1=true;
    else if (pl=='2')
    ch2=true;
}
