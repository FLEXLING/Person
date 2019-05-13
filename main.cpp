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

//Date类开始
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

//Date类结束


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

//Student类开始
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
    string number;//学号
    string type;//学生类型
    Date enrollmentDate;//入学日期
    string entranceWay;//入学方式
    string college;//学院
    string major;//专业
    int schoolLength;//学制
    string trainingLevel;//培养层次
    int grade;//年级
    int classNum;//班级
    string counsellor;//辅导员
};
//Student类结束

//Teacher类开始
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
    string jobNumber;//学号
    string college;//学院
    string major;//专业
    string office;//办公室
    string phoneNumber;//电话号码
};


//设置姓名
void setName(Person &temp){
    string name;
    cout<<"请输入姓名(2-20个汉字)：";
    cin>>name;
    bool nameRight=1;
    while(1){
        if(includeChinese(name)){
            for(int i=0;i<name.length();i++){
                if(isalpha(name[i])||ispunct(name[i])||isdigit(name[i])){
                    cout<<"姓名中不能同时含有中文和其他字符！"<<endl;
                    nameRight=false;
                    break;
                }
            }
            if(name.length()<4||name.length()>40){
                nameRight=false;
                cout<<"姓名长度错误！"<<endl;
            }
        }
        if(!nameRight){
            cout<<"请重新输入：";
            cin>>name;
            nameRight=true;
        }else{
            temp.setName(name);
            break;
        }
    }
    cout<<"姓名录入成功！"<<endl<<endl<<endl;
}

//设置性别
void setSex(Person &temp){
    int sex;
    cout<<"请选择性别(男/女)："<<endl<<"1.男   2.女"<<endl;
    cin>>sex;
    while(sex<1||sex>2){
        cout<<"输入错误，请重新输入：";
        cin>>sex;
    }
    if(sex==1){
        temp.setSex("男");
    }else if(sex==2){
        temp.setSex("女");
    }
    cout<<"性别录入成功！"<<endl<<endl<<endl;
}

//设置出生地
void setBirthPlace(Person &temp){
    string birthPlace;
    cout<<"设置出生地，请输入所在地区：";
    cin>>birthPlace;
    bool birthPlaceRight=1;
    while(1){
        if(includeChinese(birthPlace)){
            for(int i=0;i<birthPlace.length();i++){
                if(isalpha(birthPlace[i])||ispunct(birthPlace[i])||isdigit(birthPlace[i])){
                    cout<<"地址中不能同时含有中文和其他字符！"<<endl;
                    birthPlaceRight=false;
                    break;
                }
            }
        }
        if(birthPlaceRight){
            temp.setBirthPlace(birthPlace);
            break;
        }else{
            cout<<"请重新输入：";
            cin>>birthPlace;
            birthPlaceRight=true;
        }
    }
    cout<<"出生地录入成功！"<<endl<<endl<<endl;
}

//设置出生日期
void setBirthday(Person &temp){
    string birthday;
    cout<<"请输入出生日期：";
    cin>>birthday;
    int birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());//出生日期分割，并将其转化为int
    int birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
    int birthD=atoi(birthday.substr(birthday.find_last_of('.')+1,birthday.length()).c_str());
    while(!judge(birthY,birthM,birthD)){//判断错误输入
        cout<<"出生日期输入错误，请重新输入：";
        cin>>birthday;
        birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());
        birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
        birthD=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.length()).c_str());
    }
    temp.getBirthday().setDate(birthY,birthM,birthD);
    cout<<"出生日期录入成功！"<<endl<<endl<<endl;
}

//设置民族
void setNation(Person &temp){
    cout<<"民族录入，可选择民族如下："<<endl;
    string nationBuf;
    int item=0;
    string nationChoice;
    nationFile.clear();
    nationFile.seekg(0,ios::beg);
    while(!nationFile.eof()){//按照一行四个进行输出
        getline(nationFile,nationBuf);
        cout<<left<<setw(30)<<nationBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"请选择民族：";
    cin.clear();
    cin.sync();//清空cin缓冲区
    getline(cin,nationChoice);//读入选择
    if(nationChoice.size()==0){//设为默认值
        temp.setNation("汉族");
        cout<<"无有效输入，已将民族设为默认值：汉族"<<endl;
    }else{
        nationFile.clear();
        nationFile.seekg(0,ios::beg);
        int nationNum;
        while(!nationFile.eof()){//遍历文件查找对应序号
            while(!isChoice(nationChoice)){
                cout<<"输入错误，请重新选择：";
                cin>>nationChoice;
                nationFile.clear();
                nationFile.seekg(0,ios::beg);
            }
            getline(nationFile,nationBuf);
            nationNum=atoi(nationBuf.substr(0,nationBuf.find_first_of('\t')).c_str());
            if(atoi(nationChoice.c_str())==nationNum){
                cout<<"已选择："<<nationBuf<<endl;
                temp.setNation(nationBuf.substr(nationBuf.find_last_of('\t')+1,nationBuf.length()));
                break;
            }else if(nationFile.eof()&&atoi(nationChoice.c_str())!=nationNum){
                cout<<"输入错误，请重新选择：";
                cin>>nationChoice;
                nationFile.clear();
                nationFile.seekg(0,ios::beg);
            }
        }
    }
    cout<<"民族录入成功！"<<endl<<endl<<endl;
}

//设置身份证号
void setIDNumber(Person &temp){
    string IDNumber;
    while(1){
        int isIdNumberRight=1;
        cout<<"请输入身份证号：";
        cin.clear();
        cin.sync();
        cin>>IDNumber;

        //判断身份证号字符
        if(includeChinese(IDNumber)){
            cout<<"身份证号中不能含有汉字！"<<endl;
            isIdNumberRight=0;
        }
        for(int i=0;i<IDNumber.length();i++){
            if(ispunct(IDNumber[i])||isalpha(IDNumber[i])){
                cout<<"身份证号中不能含有字符或数字";
                isIdNumberRight=0;
                break;
            }
        }

        //判断身份证号长度
        if(IDNumber.length()!=18){
            cout<<"身份证号长度错误，";
            isIdNumberRight=0;
        }

        //判断行政区划
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
                    cout<<"行政区划错误，";
                    break;
                    isIdNumberRight=0;
                    adminDivisionFile.clear();
                    adminDivisionFile.seekg(0,ios::beg);
                }
            }
        }

        //判断出生日期
        if(isIdNumberRight==1){
            int IdbirthY=atoi(IDNumber.substr(6,4).c_str());//提取身份证出生日期，并将其转化为int
            int IdbirthM=atoi(IDNumber.substr(10,2).c_str());
            int IdbirthD=atoi(IDNumber.substr(12,2).c_str());
            if(IdbirthY!=temp.getBirthday().getYear()||IdbirthM!=temp.getBirthday().getMonth()
               ||IdbirthD!=temp.getBirthday().getDay()){
                isIdNumberRight=0;
                cout<<"出生日期错误，";
            }
        }

        //判断顺序码
        int intSex;
        if(temp.getSex()=="男"){
            intSex=1;
        }else if(temp.getSex()=="女"){
            intSex=0;
        }
        if(isIdNumberRight==1){
            int sequenceNum=atoi(IDNumber.substr(14,3).c_str());
            if((sequenceNum%2)==intSex){
                isIdNumberRight=1;
            }else{
                isIdNumberRight=0;
                cout<<"性别错误，";
            }
        }

        //判断校验位
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
                cout<<"检验位错误，";
            }
        }
        if(isIdNumberRight==1){
            temp.setIdNumber(IDNumber);
            cout<<"身份证号录入成功！"<<endl<<endl<<endl;
            break;
        }
    }
}

//设置父母信息
void setParent(Person &temp){
    string fatherName;
    string motherName;
    int fatherBloodType;
    int motherBloodType;
    cout<<"请输入父亲姓名：";
    cin>>fatherName;
    bool fatherNameRight=true;
    while(1){
        if(includeChinese(fatherName)){
            for(int i=0;i<fatherName.length();i++){
                if(isalpha(fatherName[i])||ispunct(fatherName[i])||isdigit(fatherName[i])){
                    cout<<"姓名中不能同时含有中文和其他字符！"<<endl;
                    fatherNameRight=false;
                    break;
                }
            }
            if(fatherName.length()<4||fatherName.length()>40){
                fatherNameRight=false;
                cout<<"姓名长度错误！"<<endl;
            }
        }
        if(fatherNameRight){
            temp.setFatherName(fatherName);
            break;
        }else{
            cout<<"请重新输入：";
            cin>>fatherName;
            fatherNameRight=true;
        }
    }
    cout<<"请输入母亲姓名：";
    cin>>motherName;
    bool motherNameRight=true;
    while(1){
        if(includeChinese(motherName)){
            for(int i=0;i<motherName.length();i++){
                if(isalpha(motherName[i])||ispunct(motherName[i])||isdigit(motherName[i])){
                    cout<<"姓名中不能同时含有中文和其他字符！"<<endl;
                    motherNameRight=false;
                    break;
                }
            }
            if(motherName.length()<4||motherName.length()>40){
                motherNameRight=false;
                cout<<"姓名长度错误！"<<endl;
            }
        }
        if(motherNameRight){
            temp.setMotherName(motherName);
            break;
        }else{
            cout<<"请重新输入：";
            cin>>motherName;
            motherNameRight=true;
        }
    }
    cout<<"请输入父亲血型：  1.O    2.A    3.B    4.AB"<<endl;
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
            cout<<"输入错误，请重新输入：";
            cin>>read;
        }
    }
    if(fatherBloodType==0){
        cout<<"已选择：O型"<<endl;
    }else if(fatherBloodType==2){
        cout<<"已选择：A型"<<endl;
    }else if(fatherBloodType==3){
        cout<<"已选择：B型"<<endl;
    }else{
        cout<<"已选择：AB型"<<endl;
    }
    cout<<"请输入母亲血型：  1.O    2.A    3.B    4.AB"<<endl;
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
            cout<<"输入错误，请重新输入：";
            cin>>read;
        }
    }
    if(motherBloodType==0){
        cout<<"已选择：O型"<<endl;
    }else if(motherBloodType==2){
        cout<<"已选择：A型"<<endl;
    }else if(motherBloodType==3){
        cout<<"已选择：B型"<<endl;
    }else{
        cout<<"已选择：AB型"<<endl;
    }
    int bloodType=fatherBloodType+motherBloodType;
    if(bloodType==0){
        temp.setBloodType("O型");
    }else if(bloodType==2||bloodType==4){
        temp.setBloodType("A型");
    }else if(bloodType==3||bloodType==6){
        temp.setBloodType("B型");
    }else if(bloodType==7||bloodType==14||bloodType==5||bloodType==9||bloodType==10){
        temp.setBloodType("AB型");
    }
    temp.setIsChild(1);
}

//设置学号
void setNumber(Student &temp){
    string number;
    cout<<"请输入学号(必须为9位)：";
    cin>>number;
    int numberRight=1;
    do{
        numberRight=1;
        if(number.length()!=9){//判断学号长度
            numberRight=0;
        }else{
            string tempCollege=number.substr(0,2);//判断学院是否正确
            string buf;
            int is=0;
            collegeFile.clear();
            collegeFile.seekg(0,ios::beg);//使学号文件指针指向开头（下同）
            while(!collegeFile.eof()){//遍历文件查找学院
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
                //判断入学年份是否为当前年份
                if((number[2]-48)!=(sysTime.wYear-2000)/10||(number[3]-48)!=(sysTime.wYear-2000)%10){
                    numberRight=0;
                }
            }
        }

        if(numberRight==0){
            cout<<"输入学号有误，请重新输入：";
            cin>>number;
        }
    }while(numberRight==0);
    temp.getEnrollmentDate().setYear(sysTime.wYear);//设置入学年份
    temp.setNumber(number);//设置学号
    cout<<"学号录入成功！"<<endl<<endl<<endl;
}

//设置政治面貌
void setPoliticStatus(Person &temp){
    cout<<"政治面貌，可选择政治面貌如下："<<endl;
    string politicsStatusBuf;
    int item=0;
    string politicsStatusChoice;
    politicsStatusFile.clear();
    politicsStatusFile.seekg(0,ios::beg);
    while(!politicsStatusFile.eof()){//输出文件选项
        getline(politicsStatusFile,politicsStatusBuf);
        cout<<left<<setw(30)<<politicsStatusBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    //读入并设置
    cout<<endl<<"请选择政治面貌：";
    cin.clear();
    cin.sync();
    getline(cin,politicsStatusChoice);
    if(politicsStatusChoice.size()==0){
        temp.setPoliticsStatus("共青团员");
        cout<<"无有效输入，已将政治面貌设为默认值：共青团员"<<endl;
    }else{
        politicsStatusFile.clear();
        politicsStatusFile.seekg(0,ios::beg);
        int politicsStatusNum;
        while(!politicsStatusFile.eof()){//遍历文件查找对应序号
            while(!isChoice(politicsStatusChoice)){
                cout<<"输入错误，请重新选择：";
                cin>>politicsStatusChoice;
            }
            getline(politicsStatusFile,politicsStatusBuf);
            politicsStatusNum=((politicsStatusBuf[0]-48)*10+(politicsStatusBuf[1]-48));
            if(atoi(politicsStatusChoice.c_str())==politicsStatusNum){
                cout<<"已选择："<<politicsStatusBuf<<endl;
                break;
            }else if(politicsStatusFile.eof()&&atoi(politicsStatusChoice.c_str())!=politicsStatusNum){
                cout<<"输入错误，请重新选择：";
                cin>>politicsStatusChoice;
                politicsStatusFile.clear();
                politicsStatusFile.seekg(0,ios::beg);
            }
        }
        temp.setPoliticsStatus(
                politicsStatusBuf.substr(politicsStatusBuf.find_last_of(' ')+1,politicsStatusBuf.length()));
    }
    cout<<"政治面貌录入成功！"<<endl<<endl<<endl;
}

//设置学生类别
void setType(Student &temp){
    cout<<"设置学生类别，可选择类别如下："<<endl;
    string typeBuf;
    int item=0;
    string typeChoice;
    typeFile.clear();
    typeFile.seekg(0,ios::beg);
    while(!typeFile.eof()){//输出文件内容
        getline(typeFile,typeBuf);
        cout<<left<<setw(15)<<typeBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"请选择学生类别：";
    cin.clear();
    cin.sync();
    getline(cin,typeChoice);
    if(typeChoice.size()==0){//设为默认值
        temp.setType("无");
        cout<<"无有效输入，已将学生类别设为默认值：无"<<endl;
    }else{
        typeFile.clear();
        typeFile.seekg(0,ios::beg);
        int typeNum;
        while(!typeFile.eof()){//遍历文件查找对应序号
            while(!isChoice(typeChoice)){
                cout<<"输入错误，请重新选择：";
                cin>>typeChoice;
            }
            getline(typeFile,typeBuf);
            typeNum=(typeBuf[0]-48);
            if(atoi(typeChoice.c_str())==typeNum){
                cout<<"已选择："<<typeBuf<<endl;
                break;
            }else if(typeFile.eof()&&atoi(typeChoice.c_str())!=typeNum){
                cout<<"输入错误，请重新选择：";
                cin>>typeChoice;
                typeFile.clear();
                typeFile.seekg(0,ios::beg);
            }
        }
        temp.setType(typeBuf.substr(typeBuf.find_last_of(' '),typeBuf.length()));
    }
    cout<<"学生类别录入成功！"<<endl<<endl<<endl;
}

//设置入学年月
void setEnrollmentDate(Student &temp){
    string enrollmentDate;
    cout<<"请输入入学日期：";
    cin>>enrollmentDate;
    int enrollY=atoi(enrollmentDate.substr(0,enrollmentDate.find_first_of('.')).c_str());//入学日期分割，并将其转化为int
    int enrollM=atoi(
            enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.find_last_of('.')).c_str());
    int enrollD=atoi(enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.length()).c_str());
    while(!(judge(enrollY,enrollM,enrollD)&&enrollM>=8&&enrollM<=10)){//判错逻辑
        cout<<"入学日期输入错误，请重新输入：";
        cin>>enrollmentDate;
        enrollY=atoi(enrollmentDate.substr(0,enrollmentDate.find_first_of('.')).c_str());
        enrollM=atoi(
                enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.find_last_of('.')).c_str());
        enrollD=atoi(enrollmentDate.substr(enrollmentDate.find_last_of('.')+1,enrollmentDate.length()).c_str());
    }
    temp.getEnrollmentDate().setDate(enrollY,enrollM,enrollD);
    cout<<"入学日期录入成功！"<<endl<<endl<<endl;
}

//设置入学方式
void setEntranceWay(Student &temp){
    cout<<"设置入学方式，可选择方式如下："<<endl;
    string entranceWayBuf;
    int item=0;
    string entranceWayChoice;
    entranceWayFile.clear();
    entranceWayFile.seekg(0,ios::beg);
    while(!entranceWayFile.eof()){//遍历文件输出
        getline(entranceWayFile,entranceWayBuf);
        cout<<left<<setw(15)<<entranceWayBuf;
    }
    cout<<endl<<"请选择入学方式：";
    cin.clear();
    cin.sync();
    getline(cin,entranceWayChoice);
    if(entranceWayChoice.size()==0){//设为默认值
        temp.setEntranceWay("普通入学");
        cout<<"无有效输入，已将入学方式设为默认值：普通入学"<<endl;
    }else{
        entranceWayFile.clear();
        entranceWayFile.seekg(0,ios::beg);
        int entranceWayNum;
        while(!entranceWayFile.eof()){//遍历文件查找对应序号
            while(!isChoice(entranceWayChoice)){
                cout<<"输入错误，请重新选择：";
                cin>>entranceWayChoice;
            }
            getline(entranceWayFile,entranceWayBuf);
            entranceWayNum=(entranceWayBuf[0]-48);
            if(atoi(entranceWayChoice.c_str())==entranceWayNum){
                cout<<"已选择："<<entranceWayBuf<<endl;
                break;
            }else if(entranceWayFile.eof()&&atoi(entranceWayChoice.c_str())!=entranceWayNum){
                cout<<"输入错误，请重新选择：";
                cin>>entranceWayChoice;
                entranceWayFile.clear();
                entranceWayFile.seekg(0,ios::beg);
            }
        }
        temp.setEntranceWay(entranceWayBuf.substr(entranceWayBuf.find_last_of(' '),entranceWayBuf.length()));
    }
    cout<<"入学方式录入成功！"<<endl<<endl<<endl;
}

//设置年级
void setGrade(Student &temp){
    int grade;
    cout<<"设置年级，请输入所在年级：";
    cin>>grade;
    int numberYear=atoi(temp.getNumber().substr(2,2).c_str());
    if(grade!=2000+atoi(temp.getNumber().substr(2,2).c_str())){
        int tempChoice;
        cout<<"输入年级与学号中年级不同，是否确定录入：1.是      2.否"<<endl;
        cin>>tempChoice;
        if(tempChoice==1){
            temp.setGrade(grade);
        }else{
            temp.setGrade(2000+atoi(temp.getNumber().substr(2,2).c_str()));
            cout<<"已选择录入学号中年份!"<<endl;
        }
    }else{
        temp.setGrade(2000+atoi(temp.getNumber().substr(2,2).c_str()));
    }
    cout<<"年级录入成功！"<<endl<<endl<<endl;
}

//设置专业名称
void setMajor(Student &temp){
    cout<<"设置专业，你的学院为："<<temp.getCollege()<<endl;
    cout<<"可选择专业如下："<<endl;
    string majorBuf;
    string majorCollege;
    int majorChoice;
    majorFile.clear();
    majorFile.seekg(0,ios::beg);
    while(!majorFile.eof()){//遍历文件输出对应学院专业
        getline(majorFile,majorCollege);
        if(majorCollege.substr(2,majorCollege.find_first_of(' ')-2)==temp.getCollege()){
            cout<<majorCollege.substr(majorCollege.find_first_of(' ')+1,majorCollege.length());
        }
    }

    cout<<endl<<"请选择：";
    cin>>majorChoice;
    majorFile.clear();
    majorFile.seekg(0,ios::beg);
    string majorNum;
    vector<string> majors;
    while(!majorFile.eof()){//遍历文件将对应专业分割存入vector对象以供选择匹配
        getline(majorFile,majorBuf);
        if(majorBuf.substr(2,majorBuf.find_first_of(' ')-2)==temp.getCollege()){
            majorBuf=majorBuf.substr(majorBuf.find_first_of(' ')+1,majorBuf.length());
            splitString(majorBuf,majors," ");
        }
    }
    int i=0;
    while(1){
        majorNum=majors[i];//遍历vector查找对应序号
        if(majorChoice==atoi(majorNum.substr(0,2).c_str())){
            cout<<"已选择："<<majorNum<<endl;
            goto here;
        }else if(i==majors.size()-1&&majorChoice!=atoi(majorNum.substr(0,1).c_str())){
            cout<<"输入错误，请重新选择：";
            cin>>majorChoice;
            i=-1;
        }
        i++;
    }
    here:temp.setMajor(majorNum.substr(2,majorNum.length()));
    cout<<"专业录入成功！"<<endl<<endl<<endl;
}

//设置专业名称
void setMajor(Teacher &temp){
    cout<<"设置专业，你的学院为："<<temp.getCollege()<<endl;
    cout<<"可选择专业如下："<<endl;
    string majorBuf;
    string majorCollege;
    int majorChoice;
    majorFile.clear();
    majorFile.seekg(0,ios::beg);
    while(!majorFile.eof()){//遍历文件输出对应学院专业
        getline(majorFile,majorCollege);
        if(majorCollege.substr(2,majorCollege.find_first_of(' ')-2)==temp.getCollege()){
            cout<<majorCollege.substr(majorCollege.find_first_of(' ')+1,majorCollege.length());
        }
    }

    cout<<endl<<"请选择：";
    cin>>majorChoice;
    majorFile.clear();
    majorFile.seekg(0,ios::beg);
    string majorNum;
    vector<string> majors;
    while(!majorFile.eof()){//遍历文件将对应专业分割存入vector对象以供选择匹配
        getline(majorFile,majorBuf);
        if(majorBuf.substr(2,majorBuf.find_first_of(' ')-2)==temp.getCollege()){
            majorBuf=majorBuf.substr(majorBuf.find_first_of(' ')+1,majorBuf.length());
            splitString(majorBuf,majors," ");
        }
    }
    int i=0;
    while(1){
        majorNum=majors[i];//遍历vector查找对应序号
        if(majorChoice==atoi(majorNum.substr(0,2).c_str())){
            cout<<"已选择："<<majorNum<<endl;
            goto here;
        }else if(i==majors.size()-1&&majorChoice!=atoi(majorNum.substr(0,1).c_str())){
            cout<<"输入错误，请重新选择：";
            cin>>majorChoice;
            i=-1;
        }
        i++;
    }
    here:temp.setMajor(majorNum.substr(2,majorNum.length()));
    cout<<"专业录入成功！"<<endl<<endl<<endl;
}

//设置学制
void setSchoolLength(Student &temp){
    if(atoi(temp.getNumber().substr(0,2).c_str())==15){//按照专业设置学制
        temp.setSchoolLength(5);
    }else if(atoi(temp.getNumber().substr(0,2).c_str())==29){
        temp.setSchoolLength(3);
    }else{
        temp.setSchoolLength(4);
    }
    cout<<"根据专业，学制已设置为："<<temp.getSchoolLength()<<endl<<endl<<endl;
}

//设置培养层次
void setTrainingLevel(Student &temp){
    if(temp.getMajor()=="研究生专业"){
        temp.setTrainingLevel("研究生");
        cout<<endl<<"专业为研究生专业\n录入培养层次：研究生"<<endl<<endl<<endl;
    }else{//非研究生专业设置为本科生
        temp.setTrainingLevel("本科生");
        cout<<endl<<"专业为本科专业\n录入培养层次：本科生"<<endl<<endl<<endl;
    }
}

//设置班级号
void setClass(Student &temp){
    string classNum;
    cout<<"设置班级号，请输入所在班级：";
    cin>>classNum;
    int intClassNum=atoi(classNum.c_str());
    while(intClassNum<0||intClassNum>10){//判错逻辑
        cout<<"班级号输入错误，请重新输入:";
        cin>>classNum;
        intClassNum=atoi(classNum.c_str());
    }
    temp.setClassNum(intClassNum);
    cout<<"班级为："<<intClassNum<<"班，班级录入成功！"<<endl<<endl<<endl;
}

//设置辅导员
void setCounsellor(Student &temp){
    cout<<"录入辅导员："<<endl;
    string major=temp.getMajor();
    string counsellorBuf;
    string counsellor;
    int exist=0;
    counsellorFile.clear();
    counsellorFile.seekg(0,ios::beg);
    while(!counsellorFile.eof()){//查找当前专业有没有辅导员信息
        getline(counsellorFile,counsellorBuf);
        if(counsellorBuf.substr(0,counsellorBuf.find_first_of(' '))==major){
            counsellor=counsellorBuf.substr(counsellorBuf.find_last_of(' ')+1,counsellorBuf.length());
            temp.setCounsellor(counsellor);
            exist=1;
            cout<<"你的专业为："<<major<<endl<<"对应辅导员为："<<counsellor<<endl;
            break;
        }
    }
    if(exist==0){//没有信息则输入
        cin>>counsellor;
        ofstream inCounsellorFile("counsellor.txt");
        inCounsellorFile<<major<<' '<<counsellor<<endl;
        temp.setCounsellor(counsellor);
        inCounsellorFile.close();
    }
    cout<<"辅导员录入成功！"<<endl<<endl<<endl;
}

//设置工号
void setJobNumber(Teacher &temp){
    string number;
    cout<<"请输入工号：";
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
            cout<<"输入学号有误，请重新输入：";
            cin>>number;
        }
    }while(numberRight==0);
    temp.setJobNumber(number);//设置工号
    cout<<"工号录入成功！"<<endl<<endl<<endl;
}

//设置学院
void setCollege(Teacher &temp){
    cout<<"设置学院，可选择如下："<<endl;
    string collegeBuf;
    int item=0;
    collegeFile.clear();
    collegeFile.seekg(0,ios::beg);
    while(!collegeFile.eof()){//遍历文件输出
        getline(collegeFile,collegeBuf);
        cout<<left<<setw(15)<<collegeBuf;
    }
    string college;
    cout<<"请输入学院：";
    cin>>college;
    int is=0;
    do{
        string buf;
        collegeFile.clear();
        collegeFile.seekg(0,ios::beg);//使学号文件指针指向开头（下同）
        while(!collegeFile.eof()){//遍历文件查找学院
            getline(collegeFile,buf);
            if(college==buf.substr(0,2)){
                is=1;
                temp.setCollege(buf.substr(3,buf.length()));
                break;
            }
        }
        if(is==0){
            cout<<"输入学院有误，请重新输入：";
            cin>>college;
        }
    }while(is==0);
    cout<<"学院录入成功！"<<endl<<endl<<endl;
}

//设置办公室
void setOffice(Teacher &temp){
    string office;
    cout<<"设置办公室，请输入所在办公室：";
    cin>>office;
    bool officeRight=1;
    while(1){
        if(includeChinese(office)){
            for(int i=0;i<office.length();i++){
                if(isalpha(office[i])||ispunct(office[i])||isdigit(office[i])){
                    cout<<"办公室中不能同时含有中文和其他字符！"<<endl;
                    officeRight=false;
                    break;
                }
            }
        }
        if(officeRight){
            temp.setOffice(office);
            break;
        }else{
            cout<<"请重新输入：";
            cin>>office;
            officeRight=true;
        }
    }
    cout<<"办公室录入成功！"<<endl<<endl<<endl;
}

//设置电话号码
void setPhoneNumber(Teacher &temp){
    string number;
    cout<<"请输入电话号码：";
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
            cout<<"输入电话号码有误，请重新输入：";
            cin>>number;
        }
    }while(numberRight==0);
    temp.setJobNumber(number);//设置电话号码
    cout<<"电话号码录入成功！"<<endl<<endl<<endl;
}

//其余函数
//判断日期合法性函数
int judge(int y,int m,int d){//判断日期是否合法
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

//判断是否含有中文函数
bool includeChinese(string str){
    char temp;
    char tempNext;
    for(int i=0;i<str.length();i++){
        temp=str[i];
        tempNext=str[i+1];
        if(temp&0x80||tempNext&0x80){//如果字符高位为1且下一字符高位也是1则有中文字符
            return true;
        }
    }
    return false;
}

//判断是否为正确选择
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

//分割字符串函数
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
    cout<<endl<<endl<<"Person测试："<<endl;
    setName(temp);
    setSex(temp);
    setBirthPlace(temp);
    setBirthday(temp);
    setNation(temp);
    setIDNumber(temp);
    int choice;
    cout<<"是否设置父母信息：1.是    2.否"<<endl;
    cin>>choice;
    while(choice<1||choice>2){
        cout<<"选择错误，请重新选择：";
        cin>>choice;
    }
    if(choice==1){
        setParent(temp);
    }else{
        int bloodType;
        cout<<"请输入血型：  1.O    2.A    3.B    4.AB"<<endl;
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
                cout<<"输入错误，请重新输入：";
                cin>>read;
            }
        }
        if(bloodType==0){
            cout<<"已选择：O型"<<endl;
            temp.setBloodType("O型");
        }else if(bloodType==2){
            cout<<"已选择：A型"<<endl;
            temp.setBloodType("A型");
        }else if(bloodType==3){
            cout<<"已选择：B型"<<endl;
            temp.setBloodType("B型");
        }else{
            cout<<"已选择：AB型"<<endl;
            temp.setBloodType("AB型");
        }
    }
    cout<<"输出信息："<<endl;
    cout<<temp.getName()<<" "<<temp.getSex()<<" "<<temp.getBirthPlace()<<" "<<
    temp.getBirthday().getYear()<<"."<<temp.getBirthday().getMonth()<<"."<<temp.getBirthday().getDay()
    <<" "<<temp.getNation()<<" "<<temp.getIdNumber()<<" ";
    if(temp.getIsChild()){
        cout<<temp.getFatherName()<<" "<<temp.getMotherName()<<" ";
    }
    cout<<temp.getBloodType();

    cout<<endl<<endl<<"Student测试："<<endl;
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

    cout<<"输出信息："<<endl;
    cout<<stu.getNumber()<<" "<<stu.getName()<<" "<<stu.getSex()<<" "<<stu.getBirthPlace()<<" "<<
        stu.getBirthday().getYear()<<"."<<stu.getBirthday().getMonth()<<"."<<stu.getBirthday().getDay()
        <<" "<<stu.getNation()<<" "<<stu.getIdNumber()<<" "<<stu.getType()<<" "<<
        stu.getEnrollmentDate().getYear()<<"."<<stu.getEnrollmentDate().getMonth()<<"."<<
        stu.getEnrollmentDate().getDay()<<" "<<stu.getEntranceWay()<<" "<<stu.getCollege()<<" "
        <<stu.getMajor()<<" "<<stu.getSchoolLength()<<" "<<stu.getTrainingLevel()<<" "
        <<stu.getGrade()<<" "<<stu.getClassNum()<<" "<<stu.getCounsellor()<<" ";

    cout<<endl<<endl<<"Teacher测试："<<endl;
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
    cout<<"输出信息："<<endl;
    cout<<tea.getJobNumber()<<" "<<tea.getName()<<" "<<tea.getSex()<<" "<<tea.getBirthPlace()<<" "<<
        tea.getBirthday().getYear()<<"."<<tea.getBirthday().getMonth()<<"."<<tea.getBirthday().getDay()
        <<" "<<tea.getNation()<<" "<<tea.getIdNumber()<<" "<<tea.getCollege()<<" "<<tea.getMajor()<<" "
        <<tea.getOffice()<<" "<<tea.getPhoneNumber()<<" ";

    return 0;
}