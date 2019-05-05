#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>

using namespace std;

fstream nationFile("nationFile.txt");
fstream adminDivisionFile("adminDivisionFile.txt");

int judge(int,int,int);
bool includeChinese(string);
bool isChoice(string);

//Date�࿪ʼ
class Date{
private:
    int year;
    int month;
    int day;
public:
    Date(){
        year=2000;
        month=1;
        day=1;
    }
    Date(int year,int month,int day);
    void setDate(int,int,int);
    void getDate(int &,int &,int &);

    int getYear(){
        return year;
    }
    int getMonth(){
        return month;
    }
    int getDay(){
        return day;
    }
    void setYear(int year){
        Date::year=year;
    }
    void setMonth(int month){
        Date::month=month;
    }
    void setDay(int day){
        Date::day=day;
    }
};

Date::Date(int year,int month,int day){
    if(judge(year,month,day)){
        this->year=year;
        this->month=month;
        this->day=day;
    }else{
        this->year=2000;
        this->month=1;
        this->day=1;
    }
}

void Date::setDate(int y,int m,int d){
    if(judge(y,m,d)==1){
        this->year=y;
        this->month=m;
        this->day=d;
    }
}

void Date::getDate(int &y,int &m,int &d){
    y=this->year;
    m=this->month;
    d=this->day;
}

//Date�����


class Person{
public:
    //getter
    string getName(){
        return name;
    }
    string getSex(){
        return sex;
    }
    string getBirthPlace(){
        return birthPlace;
    }
    Date &getBirthday(){
        return birthday;
    }
    string getNation(){
        return nation;
    }
    string getIdNumber(){
        return IDNumber;
    }
    string getFatherName(){
        return fatherName;
    }
    string getMotherName(){
        return motherName;
    }
    string getBloodType(){
        return bloodType;
    }

    int getIsChild(){
        return isChild;
    }

    //setter
    void setName(string name){
        this->name=name;
    }
    void setSex(string sex){
        this->sex=sex;
    }
    void setBirthPlace(string birthPlace){
        this->birthPlace=birthPlace;
    }
    void setBirthday(Date birthday){
        this->birthday=birthday;
    }
    void setNation(string nation){
        this->nation=nation;
    }
    void setIdNumber(string idNumber){
        this->IDNumber=idNumber;
    }
    void setFatherName(string fatherName){
        this->fatherName=fatherName;
    }
    void setMotherName(string motherName){
        this->motherName=motherName;
    }
    void setBloodType(string bloodType){
        this->bloodType=bloodType;
    }

    void setIsChild(int isChild){
        this->isChild=isChild;
    }

private:
    string name;
    string sex;
    string birthPlace;
    Date birthday;
    string nation;
    string IDNumber;
    string fatherName;
    string motherName;
    string bloodType;
    int isChild=0;
};

//��������
void setName(Person &temp){
    string name;
    cout<<"����������(2-20������)��";
    cin>>name;
    bool nameRight=1;
    while(1){
        if(includeChinese(name)){
            for(int i=0;i<name.length();i++){
                if(isalpha(name[i])||ispunct(name[i])||isdigit(name[i])){
                    cout<<"�����в���ͬʱ�������ĺ������ַ���"<<endl;
                    nameRight=false;
                    break;
                }
            }
            if(name.length()<4||name.length()>40){
                nameRight=false;
                cout<<"�������ȴ���"<<endl;
            }
        }
        if(nameRight==false){
            cout<<"���������룺";
            cin>>name;
            nameRight=true;
        }else{
            temp.setName(name);
            break;
        }
    }
    cout<<"����¼��ɹ���"<<endl<<endl<<endl;
}

//�����Ա�
void setSex(Person &temp){
    int sex;
    cout<<"��ѡ���Ա�(��/Ů)��"<<endl<<"1.��   2.Ů"<<endl;
    cin>>sex;
    while(sex<1||sex>2){
        cout<<"����������������룺";
        cin>>sex;
    }
    if(sex==1){
        temp.setSex("��");
    }else if(sex==2){
        temp.setSex("Ů");
    }
    cout<<"�Ա�¼��ɹ���"<<endl<<endl<<endl;
}

//���ó�����
void setBirthPlace(Person &temp){
    string birthPlace;
    cout<<"���ó����أ����������ڵ�����";
    cin>>birthPlace;
    bool birthPlaceRight=1;
    while(1){
        if(includeChinese(birthPlace)){
            for(int i=0;i<birthPlace.length();i++){
                if(isalpha(birthPlace[i])||ispunct(birthPlace[i])||isdigit(birthPlace[i])){
                    cout<<"��ַ�в���ͬʱ�������ĺ������ַ���"<<endl;
                    birthPlaceRight=false;
                    break;
                }
            }
        }
        if(birthPlaceRight){
            temp.setBirthPlace(birthPlace);
            break;
        }else{
            cout<<"���������룺";
            cin>>birthPlace;
            birthPlaceRight=true;
        }
    }
    cout<<"������¼��ɹ���"<<endl<<endl<<endl;
}

//���ó�������
void setBirthday(Person &temp){
    string birthday;
    cout<<"������������ڣ�";
    cin>>birthday;
    int birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());//�������ڷָ������ת��Ϊint
    int birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
    int birthD=atoi(birthday.substr(birthday.find_last_of('.')+1,birthday.length()).c_str());
    while(!judge(birthY,birthM,birthD)){//�жϴ�������
        cout<<"������������������������룺";
        cin>>birthday;
        birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());
        birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
        birthD=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.length()).c_str());
    }
    temp.getBirthday().setDate(birthY,birthM,birthD);
    cout<<"��������¼��ɹ���"<<endl<<endl<<endl;
}

//��������
void setNation(Person &temp){
    cout<<"����¼�룬��ѡ���������£�"<<endl;
    string nationBuf;
    int item=0;
    string nationChoice;
    nationFile.clear();
    nationFile.seekg(0,ios::beg);
    while(!nationFile.eof()){//����һ���ĸ��������
        getline(nationFile,nationBuf);
        cout<<left<<setw(30)<<nationBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"��ѡ�����壺";
    cin.clear();
    cin.sync();//���cin������
    getline(cin,nationChoice);//����ѡ��
    if(nationChoice.size()==0){//��ΪĬ��ֵ
        temp.setNation("����");
        cout<<"����Ч���룬�ѽ�������ΪĬ��ֵ������"<<endl;
    }else{
        nationFile.clear();
        nationFile.seekg(0,ios::beg);
        int nationNum;
        while(!nationFile.eof()){//�����ļ����Ҷ�Ӧ���
            while(!isChoice(nationChoice)){
                cout<<"�������������ѡ��";
                cin>>nationChoice;
                nationFile.clear();
                nationFile.seekg(0,ios::beg);
            }
            getline(nationFile,nationBuf);
            nationNum=atoi(nationBuf.substr(0,nationBuf.find_first_of('\t')).c_str());
            if(atoi(nationChoice.c_str())==nationNum){
                cout<<"��ѡ��"<<nationBuf<<endl;
                temp.setNation(nationBuf.substr(nationBuf.find_last_of('\t')+1,nationBuf.length()));
                break;
            }else if(nationFile.eof()&&atoi(nationChoice.c_str())!=nationNum){
                cout<<"�������������ѡ��";
                cin>>nationChoice;
                nationFile.clear();
                nationFile.seekg(0,ios::beg);
            }
        }
    }
    cout<<"����¼��ɹ���"<<endl<<endl<<endl;
}

//�������֤��
void setIDNumber(Person &temp){
    string IDNumber;
    while(1){
        int isIdNumberRight=1;
        cout<<"���������֤�ţ�";
        cin.clear();
        cin.sync();
        cin>>IDNumber;

        //�ж����֤���ַ�
        if(includeChinese(IDNumber)){
            cout<<"���֤���в��ܺ��к��֣�"<<endl;
            isIdNumberRight=0;
        }
        for(int i=0;i<IDNumber.length();i++){
            if(ispunct(IDNumber[i])||isalpha(IDNumber[i])){
                cout<<"���֤���в��ܺ����ַ�������";
                isIdNumberRight=0;
                break;
            }
        }

        //�ж����֤�ų���
        if(IDNumber.length()!=18){
            cout<<"���֤�ų��ȴ���";
            isIdNumberRight=0;
        }

        //�ж���������
        if(isIdNumberRight==1){
            string adminDivisionBuf;
            int adminDivisionNum;
            adminDivisionFile.clear();
            adminDivisionFile.seekg(0,ios::beg);
            while(!adminDivisionFile.eof()){
                getline(adminDivisionFile,adminDivisionBuf);
                adminDivisionNum=atoi(adminDivisionBuf.substr(0,6).c_str());
                int debug=atoi(IDNumber.substr(0,6).c_str());
                if(atoi(IDNumber.substr(0,6).c_str())==adminDivisionNum){
                    isIdNumberRight=1;
                    adminDivisionFile.clear();
                    adminDivisionFile.seekg(0,ios::beg);
                    break;
                }else if(adminDivisionFile.eof()&&atoi(IDNumber.substr(0,6).c_str())!=adminDivisionNum){
                    cout<<"������������";
                    break;
                    isIdNumberRight=0;
                    adminDivisionFile.clear();
                    adminDivisionFile.seekg(0,ios::beg);
                }
            }
        }

        //�жϳ�������
        if(isIdNumberRight==1){
            int IdbirthY=atoi(IDNumber.substr(6,4).c_str());//��ȡ���֤�������ڣ�������ת��Ϊint
            int IdbirthM=atoi(IDNumber.substr(10,2).c_str());
            int IdbirthD=atoi(IDNumber.substr(12,2).c_str());
            if(IdbirthY!=temp.getBirthday().getYear()||IdbirthM!=temp.getBirthday().getMonth()
               ||IdbirthD!=temp.getBirthday().getDay()){
                isIdNumberRight=0;
                cout<<"�������ڴ���";
            }
        }

        //�ж�˳����
        int intSex;
        if(temp.getSex()=="��"){
            intSex=1;
        }else if(temp.getSex()=="Ů"){
            intSex=0;
        }
        if(isIdNumberRight==1){
            int sequenceNum=atoi(IDNumber.substr(14,3).c_str());
            if((sequenceNum%2)==intSex){
                isIdNumberRight=1;
            }else{
                isIdNumberRight=0;
                cout<<"�Ա����";
            }
        }

        //�ж�У��λ
        if(isIdNumberRight==1){
            char check[11]={'1','0','X','9','8','7','6','5','4','3','2'};
            int sumNum=(IDNumber[0]-48)*7+(IDNumber[1]-48)*9+(IDNumber[2]-48)*10+(IDNumber[3]-48)*5+
                       (IDNumber[4]-48)*8+(IDNumber[5]-48)*4+(IDNumber[6]-48)*2+(IDNumber[7]-48)*1+
                       (IDNumber[8]-48)*6+(IDNumber[9]-48)*3+(IDNumber[10]-48)*7+(IDNumber[11]-48)*9+
                       (IDNumber[12]-48)*10+(IDNumber[13]-48)*5+(IDNumber[14]-48)*8+(IDNumber[15]-48)*4+
                       (IDNumber[16]-48)*2;
            char checkNum=check[sumNum%11];
            if(checkNum!=IDNumber[17]){
                isIdNumberRight=0;
                cout<<"����λ����";
            }
        }
        if(isIdNumberRight==1){
            temp.setIdNumber(IDNumber);
            cout<<"���֤��¼��ɹ���"<<endl<<endl<<endl;
            break;
        }
    }
}

//���ø�ĸ��Ϣ
void setParent(Person &temp){
    string fatherName;
    string motherName;
    int fatherBloodType;
    int motherBloodType;
    cout<<"�����븸��������";
    cin>>fatherName;
    bool fatherNameRight=true;
    while(1){
        if(includeChinese(fatherName)){
            for(int i=0;i<fatherName.length();i++){
                if(isalpha(fatherName[i])||ispunct(fatherName[i])||isdigit(fatherName[i])){
                    cout<<"�����в���ͬʱ�������ĺ������ַ���"<<endl;
                    fatherNameRight=false;
                    break;
                }
            }
            if(fatherName.length()<4||fatherName.length()>40){
                fatherNameRight=false;
                cout<<"�������ȴ���"<<endl;
            }
        }
        if(fatherNameRight){
            temp.setFatherName(fatherName);
            break;
        }else{
            cout<<"���������룺";
            cin>>fatherName;
            fatherNameRight=true;
        }
    }
    cout<<"������ĸ��������";
    cin>>motherName;
    bool motherNameRight=true;
    while(1){
        if(includeChinese(motherName)){
            for(int i=0;i<motherName.length();i++){
                if(isalpha(motherName[i])||ispunct(motherName[i])||isdigit(motherName[i])){
                    cout<<"�����в���ͬʱ�������ĺ������ַ���"<<endl;
                    motherNameRight=false;
                    break;
                }
            }
            if(motherName.length()<4||motherName.length()>40){
                motherNameRight=false;
                cout<<"�������ȴ���"<<endl;
            }
        }
        if(motherNameRight){
            temp.setMotherName(motherName);
            break;
        }else{
            cout<<"���������룺";
            cin>>motherName;
            motherNameRight=true;
        }
    }
    cout<<"�����븸��Ѫ�ͣ�  1.O    2.A    3.B    4.AB"<<endl;
    string read;
    cin>>read;
    while(1){
        if(read=="1"){
            fatherBloodType=0;
            break;
        }else if(read=="2"){
            fatherBloodType=2;
            break;
        }else if(read=="3"){
            fatherBloodType=3;
            break;
        }else if(read=="4"){
            fatherBloodType=7;
            break;
        }else{
            cout<<"����������������룺";
            cin>>read;
        }
    }
    if(fatherBloodType==0){
        cout<<"��ѡ��O��"<<endl;
    }else if(fatherBloodType==2){
        cout<<"��ѡ��A��"<<endl;
    }else if(fatherBloodType==3){
        cout<<"��ѡ��B��"<<endl;
    }else{
        cout<<"��ѡ��AB��"<<endl;
    }
    cout<<"������ĸ��Ѫ�ͣ�  1.O    2.A    3.B    4.AB"<<endl;
    cin>>read;
    while(1){
        if(read=="1"){
            motherBloodType=0;
            break;
        }else if(read=="2"){
            motherBloodType=2;
            break;
        }else if(read=="3"){
            motherBloodType=3;
            break;
        }else if(read=="4"){
            motherBloodType=7;
            break;
        }else{
            cout<<"����������������룺";
            cin>>read;
        }
    }
    if(motherBloodType==0){
        cout<<"��ѡ��O��"<<endl;
    }else if(motherBloodType==2){
        cout<<"��ѡ��A��"<<endl;
    }else if(motherBloodType==3){
        cout<<"��ѡ��B��"<<endl;
    }else{
        cout<<"��ѡ��AB��"<<endl;
    }
    int bloodType=fatherBloodType+motherBloodType;
    if(bloodType==0){
        temp.setBloodType("O��");
    }else if(bloodType==2||bloodType==4){
        temp.setBloodType("A��");
    }else if(bloodType==3||bloodType==6){
        temp.setBloodType("B��");
    }else if(bloodType==7||bloodType==14||bloodType==5||bloodType==9||bloodType==10){
        temp.setBloodType("AB��");
    }
    temp.setIsChild(1);
}


//���ຯ��
//�ж����ںϷ��Ժ���
int judge(int y,int m,int d){//�ж������Ƿ�Ϸ�
    int isRight=1;
    if(y>0&&m>0&&m<13&&d>0&&d<32){
        if(m==2){
            if(!(y%4==0&&y%100!=0||y%400==0)&&d>28){
                isRight=0;
            }else if((y%4==0&&y%100!=0||y%400==0)&&d>29){
                isRight=0;
            }
        }else if((m==4||m==6||m==9||m==11)&&d==31){
            isRight=0;
        }
    }else{
        isRight=0;
    }
    return isRight;
}

//�ж��Ƿ������ĺ���
bool includeChinese(string str){
    char temp;
    char tempNext;
    for(int i=0;i<str.length();i++){
        temp=str[i];
        tempNext=str[i+1];
        if(temp&0x80||tempNext&0x80){//����ַ���λΪ1����һ�ַ���λҲ��1���������ַ�
            return true;
        }
    }
    return false;
}

//�ж��Ƿ�Ϊ��ȷѡ��
bool isChoice(string choice){
    if(includeChinese(choice)){
        return false;
    }
    for(int i=0;i<choice.length();i++){
        if(ispunct(choice[i])||isalpha(choice[i])){
            return false;
        }
    }
    if(atoi(choice.c_str())<=0){
        return false;
    }else{
        return true;
    }
}

int main(){
    Person temp;
    setName(temp);
    setSex(temp);
    setBirthPlace(temp);
    setBirthday(temp);
    setNation(temp);
    setIDNumber(temp);
    int choice;
    cout<<"�Ƿ����ø�ĸ��Ϣ��1.��    2.��"<<endl;
    cin>>choice;
    while(choice<1||choice>2){
        cout<<"ѡ�����������ѡ��";
        cin>>choice;
    }
    if(choice==1){
        setParent(temp);
    }else{
        int bloodType;
        cout<<"������Ѫ�ͣ�  1.O    2.A    3.B    4.AB"<<endl;
        string read;
        cin>>read;
        while(1){
            if(read=="1"){
                bloodType=0;
                break;
            }else if(read=="2"){
                bloodType=2;
                break;
            }else if(read=="3"){
                bloodType=3;
                break;
            }else if(read=="4"){
                bloodType=7;
                break;
            }else{
                cout<<"����������������룺";
                cin>>read;
            }
        }
        if(bloodType==0){
            cout<<"��ѡ��O��"<<endl;
            temp.setBloodType("O��");
        }else if(bloodType==2){
            cout<<"��ѡ��A��"<<endl;
            temp.setBloodType("A��");
        }else if(bloodType==3){
            cout<<"��ѡ��B��"<<endl;
            temp.setBloodType("B��");
        }else{
            cout<<"��ѡ��AB��"<<endl;
            temp.setBloodType("AB��");
        }
    }
    cout<<"�����Ϣ��"<<endl;
    cout<<temp.getName()<<" "<<temp.getSex()<<" "<<temp.getBirthPlace()<<" "<<
    temp.getBirthday().getYear()<<"."<<temp.getBirthday().getMonth()<<"."<<temp.getBirthday().getDay()
    <<" "<<temp.getNation()<<" "<<temp.getIdNumber()<<" ";
    if(temp.getIsChild()){
        cout<<temp.getFatherName()<<" "<<temp.getMotherName()<<" ";
    }
    cout<<temp.getBloodType();
    return 0;
}