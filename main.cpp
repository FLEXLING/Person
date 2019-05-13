#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
#include<windows.h>

using namespace std;

ifstream collegeFile("college.txt");
ifstream politicsStatusFile("politicsStatus.txt");
ifstream typeFile("type.txt");
ifstream entranceWayFile("entranceWay.txt");
ifstream majorFile("major.txt");
ifstream counsellorFile("counsellor.txt");
fstream nationFile("nationFile.txt");
fstream adminDivisionFile("adminDivisionFile.txt");
SYSTEMTIME sysTime={0};


int judge(int,int,int);
bool includeChinese(string);
bool isChoice(string);
void splitString(string,vector<string> &,string);

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
    string getPoliticsStatus(){
        return politicsStatus;
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
    void setPoliticsStatus(string politicsStatus){
        this->politicsStatus=politicsStatus;
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
    string politicsStatus;
    string fatherName;
    string motherName;
    string bloodType;
    int isChild=0;
};

//Student�࿪ʼ
class Student:public Person{
public:
    string getNumber(){
        return number;
    }

    void setNumber(const string number){
        Student::number=number;
    }

    string getType(){
        return type;
    }

    void setType(const string type){
        Student::type=type;
    }

    Date &getEnrollmentDate(){
        return enrollmentDate;
    }

    void setEnrollmentDate(const Date enrollmentDate){
        Student::enrollmentDate=enrollmentDate;
    }

    string getEntranceWay(){
        return entranceWay;
    }

    void setEntranceWay(const string entranceWay){
        Student::entranceWay=entranceWay;
    }

    string getCollege(){
        return college;
    }

    void setCollege(const string college){
        Student::college=college;
    }

    string getMajor(){
        return major;
    }

    void setMajor(const string major){
        Student::major=major;
    }

    int getSchoolLength(){
        return schoolLength;
    }

    void setSchoolLength(int schoolLength){
        Student::schoolLength=schoolLength;
    }

    string getTrainingLevel(){
        return trainingLevel;
    }

    void setTrainingLevel(const string trainingLevel){
        Student::trainingLevel=trainingLevel;
    }

    int getGrade(){
        return grade;
    }

    void setGrade(int grade){
        Student::grade=grade;
    }

    int getClassNum(){
        return classNum;
    }

    void setClassNum(int classNum){
        Student::classNum=classNum;
    }

    string getCounsellor(){
        return counsellor;
    }

    void setCounsellor(const string counsellor){
        Student::counsellor=counsellor;
    }

private:
    string number;//ѧ��
    string type;//ѧ������
    Date enrollmentDate;//��ѧ����
    string entranceWay;//��ѧ��ʽ
    string college;//ѧԺ
    string major;//רҵ
    int schoolLength;//ѧ��
    string trainingLevel;//�������
    int grade;//�꼶
    int classNum;//�༶
    string counsellor;//����Ա
};
//Student�����

//Teacher�࿪ʼ
class Teacher:public Person{
public:
    string getJobNumber(){
        return jobNumber;
    }

    void setJobNumber(string jobNumber){
        this->jobNumber=jobNumber;
    }

    string getCollege(){
        return college;
    }

    void setCollege(string college){
        this->college=college;
    }

    string getMajor(){
        return major;
    }

    void setMajor(string major){
        this->major=major;
    }

    string getOffice(){
        return office;
    }

    void setOffice(string office){
        this->office=office;
    }

    string getPhoneNumber(){
        return phoneNumber;
    }

    void setPhoneNumber(string phoneNumber){
        this->phoneNumber=phoneNumber;
    }

private:
    string jobNumber;//ѧ��
    string college;//ѧԺ
    string major;//רҵ
    string office;//�칫��
    string phoneNumber;//�绰����
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
        if(!nameRight){
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

//����ѧ��
void setNumber(Student &temp){
    string number;
    cout<<"������ѧ��(����Ϊ9λ)��";
    cin>>number;
    int numberRight=1;
    do{
        numberRight=1;
        if(number.length()!=9){//�ж�ѧ�ų���
            numberRight=0;
        }else{
            string tempCollege=number.substr(0,2);//�ж�ѧԺ�Ƿ���ȷ
            string buf;
            int is=0;
            collegeFile.clear();
            collegeFile.seekg(0,ios::beg);//ʹѧ���ļ�ָ��ָ��ͷ����ͬ��
            while(!collegeFile.eof()){//�����ļ�����ѧԺ
                getline(collegeFile,buf);
                if(tempCollege==buf.substr(0,2)){
                    is=1;
                    temp.setCollege(buf.substr(3,buf.length()));
                    break;
                }
            }
            if(is==0){
                numberRight=0;
            }else{
                //�ж���ѧ����Ƿ�Ϊ��ǰ���
                if((number[2]-48)!=(sysTime.wYear-2000)/10||(number[3]-48)!=(sysTime.wYear-2000)%10){
                    numberRight=0;
                }
            }
        }

        if(numberRight==0){
            cout<<"����ѧ���������������룺";
            cin>>number;
        }
    }while(numberRight==0);
    temp.getEnrollmentDate().setYear(sysTime.wYear);//������ѧ���
    temp.setNumber(number);//����ѧ��
    cout<<"ѧ��¼��ɹ���"<<endl<<endl<<endl;
}

//����������ò
void setPoliticStatus(Person &temp){
    cout<<"������ò����ѡ��������ò���£�"<<endl;
    string politicsStatusBuf;
    int item=0;
    string politicsStatusChoice;
    politicsStatusFile.clear();
    politicsStatusFile.seekg(0,ios::beg);
    while(!politicsStatusFile.eof()){//����ļ�ѡ��
        getline(politicsStatusFile,politicsStatusBuf);
        cout<<left<<setw(30)<<politicsStatusBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    //���벢����
    cout<<endl<<"��ѡ��������ò��";
    cin.clear();
    cin.sync();
    getline(cin,politicsStatusChoice);
    if(politicsStatusChoice.size()==0){
        temp.setPoliticsStatus("������Ա");
        cout<<"����Ч���룬�ѽ�������ò��ΪĬ��ֵ��������Ա"<<endl;
    }else{
        politicsStatusFile.clear();
        politicsStatusFile.seekg(0,ios::beg);
        int politicsStatusNum;
        while(!politicsStatusFile.eof()){//�����ļ����Ҷ�Ӧ���
            while(!isChoice(politicsStatusChoice)){
                cout<<"�������������ѡ��";
                cin>>politicsStatusChoice;
            }
            getline(politicsStatusFile,politicsStatusBuf);
            politicsStatusNum=((politicsStatusBuf[0]-48)*10+(politicsStatusBuf[1]-48));
            if(atoi(politicsStatusChoice.c_str())==politicsStatusNum){
                cout<<"��ѡ��"<<politicsStatusBuf<<endl;
                break;
            }else if(politicsStatusFile.eof()&&atoi(politicsStatusChoice.c_str())!=politicsStatusNum){
                cout<<"�������������ѡ��";
                cin>>politicsStatusChoice;
                politicsStatusFile.clear();
                politicsStatusFile.seekg(0,ios::beg);
            }
        }
        temp.setPoliticsStatus(
                politicsStatusBuf.substr(politicsStatusBuf.find_last_of(' ')+1,politicsStatusBuf.length()));
    }
    cout<<"������ò¼��ɹ���"<<endl<<endl<<endl;
}

//����ѧ�����
void setType(Student &temp){
    cout<<"����ѧ����𣬿�ѡ��������£�"<<endl;
    string typeBuf;
    int item=0;
    string typeChoice;
    typeFile.clear();
    typeFile.seekg(0,ios::beg);
    while(!typeFile.eof()){//����ļ�����
        getline(typeFile,typeBuf);
        cout<<left<<setw(15)<<typeBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"��ѡ��ѧ�����";
    cin.clear();
    cin.sync();
    getline(cin,typeChoice);
    if(typeChoice.size()==0){//��ΪĬ��ֵ
        temp.setType("��");
        cout<<"����Ч���룬�ѽ�ѧ�������ΪĬ��ֵ����"<<endl;
    }else{
        typeFile.clear();
        typeFile.seekg(0,ios::beg);
        int typeNum;
        while(!typeFile.eof()){//�����ļ����Ҷ�Ӧ���
            while(!isChoice(typeChoice)){
                cout<<"�������������ѡ��";
                cin>>typeChoice;
            }
            getline(typeFile,typeBuf);
            typeNum=(typeBuf[0]-48);
            if(atoi(typeChoice.c_str())==typeNum){
                cout<<"��ѡ��"<<typeBuf<<endl;
                break;
            }else if(typeFile.eof()&&atoi(typeChoice.c_str())!=typeNum){
                cout<<"�������������ѡ��";
                cin>>typeChoice;
                typeFile.clear();
                typeFile.seekg(0,ios::beg);
            }
        }
        temp.setType(typeBuf.substr(typeBuf.find_last_of(' '),typeBuf.length()));
    }
    cout<<"ѧ�����¼��ɹ���"<<endl<<endl<<endl;
}

//������ѧ����
void setEnrollmentDate(Student &temp){
    string enrollmentDate;
    cout<<"��������ѧ���ڣ�";
    cin>>enrollmentDate;
    int enrollY=atoi(enrollmentDate.substr(0,enrollmentDate.find_first_of('.')).c_str());//��ѧ���ڷָ������ת��Ϊint
    int enrollM=atoi(
            enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.find_last_of('.')).c_str());
    int enrollD=atoi(enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.length()).c_str());
    while(!(judge(enrollY,enrollM,enrollD)&&enrollM>=8&&enrollM<=10)){//�д��߼�
        cout<<"��ѧ��������������������룺";
        cin>>enrollmentDate;
        enrollY=atoi(enrollmentDate.substr(0,enrollmentDate.find_first_of('.')).c_str());
        enrollM=atoi(
                enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.find_last_of('.')).c_str());
        enrollD=atoi(enrollmentDate.substr(enrollmentDate.find_last_of('.')+1,enrollmentDate.length()).c_str());
    }
    temp.getEnrollmentDate().setDate(enrollY,enrollM,enrollD);
    cout<<"��ѧ����¼��ɹ���"<<endl<<endl<<endl;
}

//������ѧ��ʽ
void setEntranceWay(Student &temp){
    cout<<"������ѧ��ʽ����ѡ��ʽ���£�"<<endl;
    string entranceWayBuf;
    int item=0;
    string entranceWayChoice;
    entranceWayFile.clear();
    entranceWayFile.seekg(0,ios::beg);
    while(!entranceWayFile.eof()){//�����ļ����
        getline(entranceWayFile,entranceWayBuf);
        cout<<left<<setw(15)<<entranceWayBuf;
    }
    cout<<endl<<"��ѡ����ѧ��ʽ��";
    cin.clear();
    cin.sync();
    getline(cin,entranceWayChoice);
    if(entranceWayChoice.size()==0){//��ΪĬ��ֵ
        temp.setEntranceWay("��ͨ��ѧ");
        cout<<"����Ч���룬�ѽ���ѧ��ʽ��ΪĬ��ֵ����ͨ��ѧ"<<endl;
    }else{
        entranceWayFile.clear();
        entranceWayFile.seekg(0,ios::beg);
        int entranceWayNum;
        while(!entranceWayFile.eof()){//�����ļ����Ҷ�Ӧ���
            while(!isChoice(entranceWayChoice)){
                cout<<"�������������ѡ��";
                cin>>entranceWayChoice;
            }
            getline(entranceWayFile,entranceWayBuf);
            entranceWayNum=(entranceWayBuf[0]-48);
            if(atoi(entranceWayChoice.c_str())==entranceWayNum){
                cout<<"��ѡ��"<<entranceWayBuf<<endl;
                break;
            }else if(entranceWayFile.eof()&&atoi(entranceWayChoice.c_str())!=entranceWayNum){
                cout<<"�������������ѡ��";
                cin>>entranceWayChoice;
                entranceWayFile.clear();
                entranceWayFile.seekg(0,ios::beg);
            }
        }
        temp.setEntranceWay(entranceWayBuf.substr(entranceWayBuf.find_last_of(' '),entranceWayBuf.length()));
    }
    cout<<"��ѧ��ʽ¼��ɹ���"<<endl<<endl<<endl;
}

//�����꼶
void setGrade(Student &temp){
    int grade;
    cout<<"�����꼶�������������꼶��";
    cin>>grade;
    int numberYear=atoi(temp.getNumber().substr(2,2).c_str());
    if(grade!=2000+atoi(temp.getNumber().substr(2,2).c_str())){
        int tempChoice;
        cout<<"�����꼶��ѧ�����꼶��ͬ���Ƿ�ȷ��¼�룺1.��      2.��"<<endl;
        cin>>tempChoice;
        if(tempChoice==1){
            temp.setGrade(grade);
        }else{
            temp.setGrade(2000+atoi(temp.getNumber().substr(2,2).c_str()));
            cout<<"��ѡ��¼��ѧ�������!"<<endl;
        }
    }else{
        temp.setGrade(2000+atoi(temp.getNumber().substr(2,2).c_str()));
    }
    cout<<"�꼶¼��ɹ���"<<endl<<endl<<endl;
}

//����רҵ����
void setMajor(Student &temp){
    cout<<"����רҵ�����ѧԺΪ��"<<temp.getCollege()<<endl;
    cout<<"��ѡ��רҵ���£�"<<endl;
    string majorBuf;
    string majorCollege;
    int majorChoice;
    majorFile.clear();
    majorFile.seekg(0,ios::beg);
    while(!majorFile.eof()){//�����ļ������ӦѧԺרҵ
        getline(majorFile,majorCollege);
        if(majorCollege.substr(2,majorCollege.find_first_of(' ')-2)==temp.getCollege()){
            cout<<majorCollege.substr(majorCollege.find_first_of(' ')+1,majorCollege.length());
        }
    }

    cout<<endl<<"��ѡ��";
    cin>>majorChoice;
    majorFile.clear();
    majorFile.seekg(0,ios::beg);
    string majorNum;
    vector<string> majors;
    while(!majorFile.eof()){//�����ļ�����Ӧרҵ�ָ����vector�����Թ�ѡ��ƥ��
        getline(majorFile,majorBuf);
        if(majorBuf.substr(2,majorBuf.find_first_of(' ')-2)==temp.getCollege()){
            majorBuf=majorBuf.substr(majorBuf.find_first_of(' ')+1,majorBuf.length());
            splitString(majorBuf,majors," ");
        }
    }
    int i=0;
    while(1){
        majorNum=majors[i];//����vector���Ҷ�Ӧ���
        if(majorChoice==atoi(majorNum.substr(0,2).c_str())){
            cout<<"��ѡ��"<<majorNum<<endl;
            goto here;
        }else if(i==majors.size()-1&&majorChoice!=atoi(majorNum.substr(0,1).c_str())){
            cout<<"�������������ѡ��";
            cin>>majorChoice;
            i=-1;
        }
        i++;
    }
    here:temp.setMajor(majorNum.substr(2,majorNum.length()));
    cout<<"רҵ¼��ɹ���"<<endl<<endl<<endl;
}

//����רҵ����
void setMajor(Teacher &temp){
    cout<<"����רҵ�����ѧԺΪ��"<<temp.getCollege()<<endl;
    cout<<"��ѡ��רҵ���£�"<<endl;
    string majorBuf;
    string majorCollege;
    int majorChoice;
    majorFile.clear();
    majorFile.seekg(0,ios::beg);
    while(!majorFile.eof()){//�����ļ������ӦѧԺרҵ
        getline(majorFile,majorCollege);
        if(majorCollege.substr(2,majorCollege.find_first_of(' ')-2)==temp.getCollege()){
            cout<<majorCollege.substr(majorCollege.find_first_of(' ')+1,majorCollege.length());
        }
    }

    cout<<endl<<"��ѡ��";
    cin>>majorChoice;
    majorFile.clear();
    majorFile.seekg(0,ios::beg);
    string majorNum;
    vector<string> majors;
    while(!majorFile.eof()){//�����ļ�����Ӧרҵ�ָ����vector�����Թ�ѡ��ƥ��
        getline(majorFile,majorBuf);
        if(majorBuf.substr(2,majorBuf.find_first_of(' ')-2)==temp.getCollege()){
            majorBuf=majorBuf.substr(majorBuf.find_first_of(' ')+1,majorBuf.length());
            splitString(majorBuf,majors," ");
        }
    }
    int i=0;
    while(1){
        majorNum=majors[i];//����vector���Ҷ�Ӧ���
        if(majorChoice==atoi(majorNum.substr(0,2).c_str())){
            cout<<"��ѡ��"<<majorNum<<endl;
            goto here;
        }else if(i==majors.size()-1&&majorChoice!=atoi(majorNum.substr(0,1).c_str())){
            cout<<"�������������ѡ��";
            cin>>majorChoice;
            i=-1;
        }
        i++;
    }
    here:temp.setMajor(majorNum.substr(2,majorNum.length()));
    cout<<"רҵ¼��ɹ���"<<endl<<endl<<endl;
}

//����ѧ��
void setSchoolLength(Student &temp){
    if(atoi(temp.getNumber().substr(0,2).c_str())==15){//����רҵ����ѧ��
        temp.setSchoolLength(5);
    }else if(atoi(temp.getNumber().substr(0,2).c_str())==29){
        temp.setSchoolLength(3);
    }else{
        temp.setSchoolLength(4);
    }
    cout<<"����רҵ��ѧ��������Ϊ��"<<temp.getSchoolLength()<<endl<<endl<<endl;
}

//�����������
void setTrainingLevel(Student &temp){
    if(temp.getMajor()=="�о���רҵ"){
        temp.setTrainingLevel("�о���");
        cout<<endl<<"רҵΪ�о���רҵ\n¼��������Σ��о���"<<endl<<endl<<endl;
    }else{//���о���רҵ����Ϊ������
        temp.setTrainingLevel("������");
        cout<<endl<<"רҵΪ����רҵ\n¼��������Σ�������"<<endl<<endl<<endl;
    }
}

//���ð༶��
void setClass(Student &temp){
    string classNum;
    cout<<"���ð༶�ţ����������ڰ༶��";
    cin>>classNum;
    int intClassNum=atoi(classNum.c_str());
    while(intClassNum<0||intClassNum>10){//�д��߼�
        cout<<"�༶�������������������:";
        cin>>classNum;
        intClassNum=atoi(classNum.c_str());
    }
    temp.setClassNum(intClassNum);
    cout<<"�༶Ϊ��"<<intClassNum<<"�࣬�༶¼��ɹ���"<<endl<<endl<<endl;
}

//���ø���Ա
void setCounsellor(Student &temp){
    cout<<"¼�븨��Ա��"<<endl;
    string major=temp.getMajor();
    string counsellorBuf;
    string counsellor;
    int exist=0;
    counsellorFile.clear();
    counsellorFile.seekg(0,ios::beg);
    while(!counsellorFile.eof()){//���ҵ�ǰרҵ��û�и���Ա��Ϣ
        getline(counsellorFile,counsellorBuf);
        if(counsellorBuf.substr(0,counsellorBuf.find_first_of(' '))==major){
            counsellor=counsellorBuf.substr(counsellorBuf.find_last_of(' ')+1,counsellorBuf.length());
            temp.setCounsellor(counsellor);
            exist=1;
            cout<<"���רҵΪ��"<<major<<endl<<"��Ӧ����ԱΪ��"<<counsellor<<endl;
            break;
        }
    }
    if(exist==0){//û����Ϣ������
        cin>>counsellor;
        ofstream inCounsellorFile("counsellor.txt");
        inCounsellorFile<<major<<' '<<counsellor<<endl;
        temp.setCounsellor(counsellor);
        inCounsellorFile.close();
    }
    cout<<"����Ա¼��ɹ���"<<endl<<endl<<endl;
}

//���ù���
void setJobNumber(Teacher &temp){
    string number;
    cout<<"�����빤�ţ�";
    cin>>number;
    int numberRight=1;
    do{
        numberRight=1;
        if(includeChinese(number)){
            numberRight=0;
        }
        for(int i=0;i<number.length();i++){
            if(isalpha(number[i])||ispunct(number[i])){
                numberRight=0;
                break;
            }
        }

        if(numberRight==0){
            cout<<"����ѧ���������������룺";
            cin>>number;
        }
    }while(numberRight==0);
    temp.setJobNumber(number);//���ù���
    cout<<"����¼��ɹ���"<<endl<<endl<<endl;
}

//����ѧԺ
void setCollege(Teacher &temp){
    cout<<"����ѧԺ����ѡ�����£�"<<endl;
    string collegeBuf;
    int item=0;
    collegeFile.clear();
    collegeFile.seekg(0,ios::beg);
    while(!collegeFile.eof()){//�����ļ����
        getline(collegeFile,collegeBuf);
        cout<<left<<setw(15)<<collegeBuf;
    }
    string college;
    cout<<"������ѧԺ��";
    cin>>college;
    int is=0;
    do{
        string buf;
        collegeFile.clear();
        collegeFile.seekg(0,ios::beg);//ʹѧ���ļ�ָ��ָ��ͷ����ͬ��
        while(!collegeFile.eof()){//�����ļ�����ѧԺ
            getline(collegeFile,buf);
            if(college==buf.substr(0,2)){
                is=1;
                temp.setCollege(buf.substr(3,buf.length()));
                break;
            }
        }
        if(is==0){
            cout<<"����ѧԺ�������������룺";
            cin>>college;
        }
    }while(is==0);
    cout<<"ѧԺ¼��ɹ���"<<endl<<endl<<endl;
}

//���ð칫��
void setOffice(Teacher &temp){
    string office;
    cout<<"���ð칫�ң����������ڰ칫�ң�";
    cin>>office;
    bool officeRight=1;
    while(1){
        if(includeChinese(office)){
            for(int i=0;i<office.length();i++){
                if(isalpha(office[i])||ispunct(office[i])||isdigit(office[i])){
                    cout<<"�칫���в���ͬʱ�������ĺ������ַ���"<<endl;
                    officeRight=false;
                    break;
                }
            }
        }
        if(officeRight){
            temp.setOffice(office);
            break;
        }else{
            cout<<"���������룺";
            cin>>office;
            officeRight=true;
        }
    }
    cout<<"�칫��¼��ɹ���"<<endl<<endl<<endl;
}

//���õ绰����
void setPhoneNumber(Teacher &temp){
    string number;
    cout<<"������绰���룺";
    cin>>number;
    int numberRight=1;
    do{
        numberRight=1;
        if(includeChinese(number)){
            numberRight=0;
        }
        for(int i=0;i<number.length();i++){
            if(isalpha(number[i])||ispunct(number[i])){
                numberRight=0;
                break;
            }
        }

        if(numberRight==0){
            cout<<"����绰�����������������룺";
            cin>>number;
        }
    }while(numberRight==0);
    temp.setJobNumber(number);//���õ绰����
    cout<<"�绰����¼��ɹ���"<<endl<<endl<<endl;
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

//�ָ��ַ�������
void splitString(string s,vector<string> &v,string c){
    int pos1,pos2;
    pos2=s.find(c);
    pos1=0;
    while(string::npos!=pos2){
        if(pos1!=pos2){
            v.push_back(s.substr(pos1,pos2-pos1));
        }
        pos1=pos2+c.size();
        pos2=s.find(c,pos1);
    }
    if(pos1!=s.length())
        v.push_back(s.substr(pos1));
}


int main(){
    Person temp;
    cout<<endl<<endl<<"Person���ԣ�"<<endl;
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

    cout<<endl<<endl<<"Student���ԣ�"<<endl;
    Student stu;
    setNumber(stu);
    setName(stu);
    setSex(stu);
    setBirthPlace(stu);
    setBirthday(stu);
    setNation(stu);
    setIDNumber(stu);
    setType(stu);
    setEnrollmentDate(stu);
    setEntranceWay(stu);
    setMajor(stu);
    setSchoolLength(stu);
    setTrainingLevel(stu);
    setGrade(stu);
    setClass(stu);
    setCounsellor(stu);

    cout<<"�����Ϣ��"<<endl;
    cout<<stu.getNumber()<<" "<<stu.getName()<<" "<<stu.getSex()<<" "<<stu.getBirthPlace()<<" "<<
        stu.getBirthday().getYear()<<"."<<stu.getBirthday().getMonth()<<"."<<stu.getBirthday().getDay()
        <<" "<<stu.getNation()<<" "<<stu.getIdNumber()<<" "<<stu.getType()<<" "<<
        stu.getEnrollmentDate().getYear()<<"."<<stu.getEnrollmentDate().getMonth()<<"."<<
        stu.getEnrollmentDate().getDay()<<" "<<stu.getEntranceWay()<<" "<<stu.getCollege()<<" "
        <<stu.getMajor()<<" "<<stu.getSchoolLength()<<" "<<stu.getTrainingLevel()<<" "
        <<stu.getGrade()<<" "<<stu.getClassNum()<<" "<<stu.getCounsellor()<<" ";

    cout<<endl<<endl<<"Teacher���ԣ�"<<endl;
    Teacher tea;
    setName(tea);
    setSex(tea);
    setBirthPlace(tea);
    setBirthday(tea);
    setNation(tea);
    setIDNumber(tea);
    setJobNumber(tea);
    setCollege(tea);
    setMajor(tea);
    setOffice(tea);
    setPhoneNumber(tea);
    cout<<"�����Ϣ��"<<endl;
    cout<<tea.getJobNumber()<<" "<<tea.getName()<<" "<<tea.getSex()<<" "<<tea.getBirthPlace()<<" "<<
        tea.getBirthday().getYear()<<"."<<tea.getBirthday().getMonth()<<"."<<tea.getBirthday().getDay()
        <<" "<<tea.getNation()<<" "<<tea.getIdNumber()<<" "<<tea.getCollege()<<" "<<tea.getMajor()<<" "
        <<tea.getOffice()<<" "<<tea.getPhoneNumber()<<" ";

    return 0;
}