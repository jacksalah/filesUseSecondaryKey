#include<bits/stdc++.h>
#include<strstream>
using namespace std;
class models
{
    int next;
    int headersize;
    struct primaryindex
    {
        char primkey[30];
        int offset;
    };
    struct secondrykey
    {
        char pr[30];
        char mod[30];
        int offset;
    };
    const static int indexSize = 100;
    primaryindex index[indexSize];
    secondrykey index1[indexSize];

    char dataFilePath[20]="dataFile.txt";
    char indexprimaryFilePath[20]="pindexFile.txt";
    char indexsecondryFilePath[20]="secondryindexFile.txt";
    models()
    {
        next=0;
        headersize=-1;
    }
    struct electronics
    {
        char  price[30] ;
        char model[30];
        char id[30];
        char description [30];
    };

    void add( fstream &stream,electronics ad);
    short find1( fstream& f, char id[] );
    void delete1( fstream& f, char id[] );
    void write_to_f(fstream& f, electronics ad);

    void sortIndex()
    {
        int len = next - 1;
        primkey temp;
        for (int i = 0; i<len; i++)
            for (int j = 0; j<len - i; j++)
            {
                if (atoi(index[j].PK)>atoi(index[j + 1].PK))
                {
                    temp = index[j];
                    index[j] = index[j + 1];
                    index[j + 1] = temp;
                }
            }
    }
   
    void ChangeIndexState(bool state)
    {
        fstream fout(dataFilePath, ios::out| ios::in);
        fout.seekp(0, ios::beg);
        fout << state;
        fout.close();
    }
    void add ()
    {
        char record[150];
        char s[50];
        ofstream fout,pindex,psecindex;
        fout.open(dataFilePath, ios::app|ios::out | ios::binary);
        fout.open(indexprimaryFilePath, ios::app|ios::out | ios::binary);
        fout.open(indexsecondryFilePath, ios::app|ios::out | ios::binary);
        electronics s;
        cout << "Enter ID: "<<endl;
        cin.getline(s.id,30);
        cout << "Enter model: "<<endl;
        cin.getline(s.model,30);
        cout << "Enter description: "<<endl;
        cin.getline(s.description,30);
        cout << "Enter price: "<<endl;
        cin.getline(s.price,30);

        strcpy(record, ad.id);
        strcat(record, "#");
        strcat(record, ad.description);
        strcat(record, "#");
        strcat(record,ad.model);
        strcat(record, "#");
        strcat(record,price);
        strcat(record, "#");
        fout.seekp(0, ios::end);
        int addess = fout.tellp();
        fout.write((char*)&len, sizeof(len));
        fout.write(buffer, len);
        primaryindex temp;
        secondrykey temp2;
        strcpy(temp.PK, s.ID);
        strcpy(temp2.pr, s.price);
        strcat(temp2.mod, s.model);
        temp.offset = address;
        temp2.offset=address;
        index[next] = temp;
        index1[next]=temp2;
        next++;
        sortIndex();
        fout.close();
    }

    int IndexBinarySearch(char key[])
    {
        int siz = next;
        int low = 0, high = siz - 1;
        while (low <= high)
        {
            int middle = (low + high) / 2;
            if (strcmp(index[middle].PK, key) == 0)
                return index[middle];
            else if (atoi(index[middle].PK)<atoi(key))
                low = middle + 1;
            else
                high = middle - 1;
        }
        return -1;
    }
    int secondryindexBinarySearch(char key[],char num[])
    {
        int siz = next;
        int low = 0;
        high = siz - 1;
        while (low <= high)
        {
            int middle = (low + high) / 2;
            if (strcmp(index1[middle].key,models) == 0&&index1[middle].num,price) == 0)
            {
                return index1[middle],index1[middle];
            }
            else if (atoi(index[middle].PK)<atoi(key))
                low = middle + 1;
                else
                    high = middle - 1;
                }
        return -1;
        int secondryindexBinarySearch_using model(char key[])
        {
            int siz = next;
            int low = 0, high = siz - 1;
            while (low <= high)
            {
                int middle = (low + high) / 2;
                if (strcmp(index1[middle].key,models) == 0&&)
                {
                    return middle;
                }
                else if (atoi(index[middle].PK)<atoi(key))
                    low = middle + 1;
                else
                    high = middle - 1;
            }
            return -1;
        }
        void deleteStudent()
        {
            ChangeIndexState(true);
            char PK[6];
            cout << "\nenter PK to delete \n";
            cin >> PK;
            fstream fout(dataFilePath, ios::binary | ios::out | ios::in);
            int address = IndexBinarySearch(PK);
            if (address == -1)
            {
                cout << "\nStudent not found";
                return;
            }
            fout.seekp(index[address].offset +2, ios::beg);
            fout << '*';
            fout.seekp(index1[address].offset +2, ios::beg);
            fout << '*';
            for (int i = address; i<next - 1; i++)
            {
                index[i] = index[i + 1];
            }
            for (int i = address; i<next - 1; i++)
            {
                index[i] = index[i + 1];
            }
            next--;
            fout.close();
        }
       
        void update(fstream &f,char *id)
        {

            short offset= find1(f,id);
            openf(f);
            cin.ignore();
            electronics ad;
            cin>>ad;

            f.seekp(offset, ios::beg);
            short len;
            f.read((char *) &len, sizeof len);
            f.read((char *) &len, sizeof len);
            f.close();

            char record[150];
            char s[50];
            stringstream fizpo;
            fizpo<<ad.price;
            fizpo>>s;
            strcpy(record, ad.id);
            strcat(record, "#");
            strcat(record, ad.brand);
            strcat(record, "#");
            strcat(record,ad.name);
            strcat(record, "#");
            strcat(record,s);
            strcat(record, "#");

            short len1 = strlen(record);

            if (len1 <=len)
            {
                openf(f);
                f.seekp(offset, ios::beg);
                short l = -2;
                f.write((char *) &l, sizeof l);
                f.write((char *) &len, sizeof len);
                f.write(record, len1);
                f.close();
                return ;
            }
            else
            {
                openf(f);
                delete1(f,id);
                f.seekg(0,ios::end) ;
                f<<len;
                f.write(record,len1);
                f<<endl;
                f.close();

            }
        }

        void compactFile(fstream& f)
        {
            f.open("elndafa.txt", ios::trunc);
            f.close();
            openf(f);
            f.seekp(0,ios::beg);
            short l, s,a = f.tellp(),h=f.tellp();
            f.read((char *) &l, sizeof l);
            f.close();
            if (l==-1)
            {
                cout<<"El file ndeef ya couch"<<endl;
                return;
            }
            else
            {
                openf(f);
                while(!f.eof())
                {
                    char buff[150] = {0};
                    f.seekp(a,ios::beg);
                    f.read((char *) &l, sizeof l);
                    if(f.fail())
                    {
                        f.close();
                        break;
                    }
                    f.read((char *) &s, sizeof s);
                    f.read(buff, s);
                    a=f.tellp();
                    f.close();
                    if(l!=-2)
                    {
                        openf1(f);
                        f.seekp(h,ios::beg);
                        f.write((char *) &l, sizeof l);
                        f.write((char *) &s, sizeof s);
                        f.write(buff, s);
                        h=f.tellp();
                        f.close();
                    }
                }
            }
            f.open("mezo.txt", ios::trunc);
            f.close();
            checker(f);
            openf1(f);

            while(!f.eof())
            {
                char buff[150] = {0};
                f.seekp(a,ios::beg);
                f.read((char *) &l, sizeof l);
                if(f.fail())
                {
                    f.close();
                    break;
                }
                f.read((char *) &s, sizeof s);
                f.read(buff, s);
                a=f.tellp();
                f.close();
                openf(f);
                f.seekp(a,ios::beg);
                f.write((char *) &l, sizeof l);
                f.write((char *) &s, sizeof s);
                f.write(buff, s);
                f.close();

            }
        }


    }
};
int main()
{
    fstream f;
    f.open( "mezo.txt", ios::in|ios::out|ios::trunc ) ;
    short avl = -1 ;
    f.seekp(0,ios::beg) ;
    f.write( (char*)&avl,sizeof(avl) ) ;
    avl = 0;
    f.write( (char*)&avl,sizeof(avl) ) ;
    f.close();
    electronics ad;
    bool k=true;
    short n;
    while (k)
    {
        cout<<"1) add "<<endl;
        cout<<"2) update "<<endl;
        cout<<"3) delete "<<endl;
        cout<<"4) search "<<endl;
        cout<<"5) compact "<<endl;
        cout<<"6) exit "<<endl;
        cin >>n;
        cin.ignore();
        if (n==1)
        {
            cin>>ad;
            add(f,ad);
        }
        else  if (n==2)
        {
            cout<<"what 'is id of device ";
            cin>>ad.id;
            update(f,ad.id);
        }
        else if (n==3)
        {
            cout<<"what 'is id of device ";
            cin>>ad.id;
            delete1(f,ad.id);
        }
        else if (n==4)
        {
            cout<<"what 'is id of device ";
            cin>>ad.id;
            char buff[200] = { 0 };
            short l ;
            short pos=find1(f,ad.id);
            if(pos != -1)
            {
                openf(f);
                f.seekp(pos,ios::beg);
                f.read((char*)&l,sizeof l);
                f.read((char*)&l,sizeof l);
                f.read((char*)&buff,l);
                f.close();
                for(int i =  0 ; i < l; i++)
                {
                    if(buff[i] == '#')
                    {
                        cout<<endl;
                        continue;
                    }
                    cout<<buff[i] ;
                }
            }
        }
        else if( n == 5)
        {
            compactFile(f);
        }
        else  if (n==6)
        {
            cout<<"the f exit :D ";
            k=false;
        }
        else
        {
            cout<<"please choose again ,, wrong choise "<<endl;
            cin>>n;
        }
        //checker(f);
    }
    return 0;
}
