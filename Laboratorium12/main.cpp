//Kod z zajec 11 pochodzi od Pauliny G.
#include <iostream>
#include "VectoredList.h"
using namespace std;

int main() {/*
    cout << endl << "[ TEST 1 ]" << endl;
    VectoredList v;
    for (int i = 0; i < 101; ++i)
        v.push_back(to_string(i));
    for (int i = 0; i < 101; ++i)
    {
        cout<< v[100-i]<<" ";
        if (i % 10 == 0)
            cout << endl;
    }
    cout << endl << "[ TEST 4 ]" << endl;
    VectoredList v2;
    v2.push_back(to_string(2));
    cout << "Size before using = "<<v2.get_size() << endl;
    v2 = v;
    for (int i = 0; i <= v2.get_size(); ++i)
    {
        cout << v2[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    }
    cout << endl << "\n[ TEST begin() i end(), ++, *]" << endl;
    VectoredList::VectoredListIterator it(v2);
    cout << it.get() <<endl;
    ++it;
    cout << it.get() <<endl;
    VectoredList::VectoredListIterator it2(v2,15);
    cout << it2.get() <<endl;
    cout<< "*it2: "<< *it2 << endl;
    cout<< "v2 begin(): "<< v2.begin().get() << endl;
    cout<< "v2 end(): "<< v2.end().get() << endl;
    cout<< "return index it2: "<< it2.return_index(v2) << endl;
    cout << endl << "[TEST ZAKRESOWE FOR]" << endl;;
    for (const auto& element : v2)
    {
        cout << element << endl;
    }

    cout << endl << "[ TEST 3 erase ]" << endl;
    //doadanie 22 elementow
    for(int i =0; i < 22; ++i)
    {
        v2.push_back(to_string(22+i));
    }
    cout <<"Size before erasing: " <<v2.get_size() << endl;
    //usuwanie 3-ego elementu
    VectoredList::VectoredListIterator it3(v2,3);
    v2.erase(it3);
    cout <<"Size after erasing: " <<v2.get_size() << endl;
    for (int i = 0; i < v2.get_size(); ++i)
    {
        cout << v2[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    }
    cout << endl << "[ TEST 3 erase(it1,it2) ]" << endl;
    cout <<"Size before erasing: " <<v2.get_size() << endl;
    VectoredList::VectoredListIterator it4(v2,3);
    VectoredList::VectoredListIterator it5(v2,13);
    v2.erase(it4,it5);
    cout <<"Size after erasing: " <<v2.get_size() << endl;
    for (int i = 0; i < v2.get_size(); ++i)
    {
        cout << v2[i] << " ";
        if (i % 10 == 0)
            cout << endl;
    }
    cout << endl << "[ TEST 5 erase(it1,it2) ]" << endl;
    VectoredList v3;
    for (int i = 0; i < 103; ++i)
        v3.push_back(to_string(i));
    for (int i = 0; i < v3.get_size(); ++i)
    {
        cout << v3[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    }
    cout << endl;
    VectoredList::VectoredListIterator it6(v3,87);
    VectoredList::VectoredListIterator it7(v3,100);
    v3.erase(it6,it7);
    cout<< "AFTER: "<< endl;
    for (int i = 0; i < v3.get_size(); ++i)
    {
        cout << v3[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    }
    */

    //moje
    /*
    // Konstruktor przenoszacy
    VectoredList v1;
    for (int i = 0; i < 10; ++i)
        v1.push_back(to_string(i));
    cout<<"Zawartosc v1: "<<endl;
    for (int i = 0; i < 10; ++i)
        cout<< v1[i]<<endl;
    cout<<"\nDane v1:\nRozmiar:"<<v1.get_size()<<"\nCapacity:"<<v1.capacity<<endl;
    cout<<"Tworze v2 i przenosze zawartosc v1 do v2: "<<endl;
    const VectoredList v2 = move(v1);
    cout<<"Zawartosc v2: "<<endl;
    for (int i = 0; i < 10; ++i)
        cout<< v2[i]<<endl;
    cout<<"Dane v2:\nRozmiar:"<<v2.get_size()<<"\nCapacity:"<<v2.capacity<<endl;
    cout<<"\nDane v1:\nRozmiar:"<<v1.get_size()<<"\nCapacity:"<<v1.capacity<<endl;
    // dziala

    //przenoszacy operator=
    VectoredList v4;
    for (int i = 0; i < 10; ++i)
        v4.push_back(to_string(i));

    cout<<"Zawartosc v4: "<<endl;
    for (int i = 0; i < 10; ++i)
        cout<< v4[i]<<endl;

    cout<<"Tworze v3\n"<<endl;
    VectoredList v3;
    cout<<"Dane v3:\nRozmiar:"<<v3.get_size()<<"\nCapacity:"<<v3.capacity<<endl;
    cout<<"Przenosze v4 do v3 za pomoca move()\n"<<endl;
    v3 = move(v4);
    cout<<"Dane v4:\nRozmiar:"<<v4.get_size()<<"\nCapacity:"<<v4.capacity<<endl;
    cout<<"Dane v3:\nRozmiar:"<<v3.get_size()<<"\nCapacity:"<<v3.capacity<<endl;
    cout<<"Zawartosc v3: "<<endl;
    for (int i = 0; i < 10; ++i)
        cout<< v3[i]<<endl;
    //dziala


    VectoredList v5, v6;
    for (int i = 0; i < 10; ++i) {
        v5.push_back(to_string(i));
        v6.push_back(to_string(i+15));
    }
    cout<<"Zawartosc v5: "<<endl;
    for (int i = 0; i < 10; ++i)
        cout<< v5[i] <<"\t";
    cout<<endl;
    cout<<"Zawartosc v6: "<<endl;
    for (int i = 0; i < 10; ++i)
        cout<< v6[i] <<"\t";
    cout<<endl;
    cout<<"Dane v5:\nRozmiar:"<<v5.get_size()<<"\nCapacity:"<<v5.capacity<<endl;
    cout<<"Dane v6:\nRozmiar:"<<v6.get_size()<<"\nCapacity:"<<v6.capacity<<endl;
    cout<<"Tworze nowy obiekt vectoredlist i uzywam operatora +"<<endl;
    VectoredList v7;
    cout<<"Dane v7:\nRozmiar:"<<v7.get_size()<<"\nCapacity:"<<v7.capacity<<endl;
    v7 = v5 + v6;
    cout<<"Zawartosc v7 po dodaniu: "<<endl;
    for (size_t index = 0; index < v7.get_size();++index)
        cout << v7[index] << "\t";
    cout<<endl;
    cout<<"Dane v7:\nRozmiar:"<<v7.get_size()<<"\nCapacity:"<<v7.capacity<<endl;
    //dziala
    */
    //metoda assign
    vector<string> vs;
    for (int i = 0; i < 10; ++i)
        vs.push_back(to_string(i));
    cout<<"Zawartosc vectora: "<<endl;
    for(auto &it: vs)
        cout<<it<<"\t";
    cout<<endl;
    VectoredList v8;
    cout<<"Dane v8 przed przeniesieniem:\nRozmiar:"<<v8.get_size()<<"\nCapacity:"<<v8.capacity<<endl;
    cout<<"Dane vs przed przeniesieniem:\nRozmiar:"<<vs.size()<<"\nCapacity:"<<vs.capacity()<<endl;
    v8.assign(move(vs));
    cout<<"Zawartosc v8:"<<endl;
    for (size_t index = 0; index < v8.get_size();++index)
        cout << v8[index] << "\t";
    cout<<endl;
    cout<<"Dane v8 po przeniesiu:\nRozmiar:"<<v8.get_size()<<"\nCapacity:"<<v8.capacity<<endl;
    cout<<"Dane vs po przeniesieniu:\nRozmiar:"<<vs.size()<<"\nCapacity:"<<vs.capacity()<<endl;

    return 0;
}