#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>
#include "mapa.h"
#include <iterator>
#include <algorithm>
#include <forward_list>

using std::cout;
using std::string;
using std::make_pair;
using std::pair;
using std::iterator;

int main() {
    /*
    //std::cout << "Hello, World!" << std::endl;
    std::map<string,string> nazvyMesiace;
    std::map<string,std::pair<int,int>>dniMesiace;
    std::vector<pair<string,string>>nazvyMesiaceVektor;
    auto cmp=[](auto i, auto j){return i.second<j.second;};
    std::multimap<std::pair<int,int>,string,decltype(cmp)>dniMesiaceSort(cmp);

    dniMesiace["Januar"]={31,1};
    dniMesiace["Februar"]={28,2};
    dniMesiace["Marec"]={31,3};
    dniMesiace["April"]={30,4};
    dniMesiace["Maj"]={31,5};
    dniMesiace["Jun"]={30,6};
    dniMesiace["Jul"]={31,7};
    dniMesiace["August"]={31,8};
    dniMesiace["September"]={30,9};
    dniMesiace["Oktober"]={31,10};
    dniMesiace["November"]={30,11};
    dniMesiace["December"]={31,12};

    for(auto &i : dniMesiace)
    {
        dniMesiaceSort.insert({i.second,i.first});
    }

    nazvyMesiace.insert(make_pair("Marec","Brezen"));
    nazvyMesiace.insert(make_pair("April","Duben"));
    nazvyMesiace.insert(make_pair("Maj","Kveten"));
    nazvyMesiace.insert(make_pair("Jun","Cerven"));
    nazvyMesiace.insert(make_pair("Jul","Cervenec"));
    cout<<"vektor";

    std::copy(nazvyMesiace.begin(),nazvyMesiace.end(),std::back_inserter(nazvyMesiaceVektor));
    std::sort(nazvyMesiaceVektor.begin(),nazvyMesiaceVektor.end(),[](auto i, auto j){return  i.second<i.first;});
    for(auto i: nazvyMesiaceVektor)
    {
        cout<<"mesiac: "<<i.first<<" dni: "<<i.second<<std::endl;
    }
    cout<<"\n";
    for(auto i: dniMesiaceSort)
    {
        cout<<"mesiac: "<<i.second<<" dni: "<<i.first.first<<std::endl;
    }
    cout<<"\n";

    //otvorime textovy subor a spocitame kolkokrat sa v nom vyskytuje kazde slovo
    std::ifstream fin("text.txt");
    string slovo;
    std::map<string,int>slova;
    while(fin>>slovo)
    {
        slova[slovo]++;
    }
    for(auto i: slova)
    {
        cout<<i.first<<" "<<i.second<<" krat"<<std::endl;
    }
    auto najviac = std::max_element(slova.begin(),slova.end(),[](auto i, auto j){return i.second<j.second;});
    cout<<"Najcastejsie je:"<<najviac->first<<" "<<najviac->second<<" krat."<<std::endl;
    //

    std::vector<std::pair<string,int>> poctyTried;
    std::copy(slova.begin(),slova.end(),std::back_inserter(poctyTried));
    std::sort(poctyTried.begin(),poctyTried.end(),[](auto i, auto j){return  i.second<j.second;});
    for(auto i: poctyTried)
    {
        cout<<i.second<<" "<<i.first<<std::endl;
    }
     */
    //kontrola chýb v hesle
/*
    std::map<string,string>heslo;
    auto zac=heslo.begin();
    auto kon=heslo.end();
    cout<<(((find_if(zac,kon,[](auto i){return isupper(i);}))!=kon)?"velke OK\n":"velke zle\n");
    cout<<(((find_if(zac,kon,[](auto i){return islower(i);}))!=kon)?"male OK\n":"male zle\n");
    cout<<(((find_if(zac,kon,[](auto i){return isdigit(i);}))!=kon)?"cislica OK\n":"cislicazle\n");
    cout<<(((find_if(zac,kon,[](auto i){return i==".";}))!=kon)?"bodka OK\n":"bodka zle\n");
    cout<<(((find_if(zac,kon,[](auto i){return isspace(i);}))!=kon)?"medzera OK\n":"medzera zle\n");

    cout<<(((std::count_if(zac,kon,[](auto i){return isupper(i);}))>0)?"velke OK\n":"velke zle\n");
    cout<<(((std::count_if(zac,kon,[](auto i){return islower(i);}))>0)?"male OK\n":"male zle\n");
    cout<<(((std::count_if(zac,kon,[](auto i){return isdigit(i);}))>0)?"cislica OK\n":"cislicazle\n");
    cout<<(((std::count_if(zac,kon,[](auto i){return i==".";}))>0)?"bodka OK\n":"bodka zle\n");
    cout<<(((std::count_if(zac,kon,[](auto i){return isspace(i);}))==0)?"medzera OK\n":"medzera zle\n");

    cout<<(((std::any_of(zac,kon,[](auto i){return isupper(i);})))?"velke OK\n":"velke zle\n");
    cout<<(((std::any_of(zac,kon,[](auto i){return islower(i);})))?"male OK\n":"male zle\n");
    cout<<(((std::any_of(zac,kon,[](auto i){return isdigit(i);})))?"cislica OK\n":"cislicazle\n");
    cout<<(((std::any_of(zac,kon,[](auto i){return i==".";})))?"bodka OK\n":"bodka zle\n");
    cout<<(((std::none_of(zac,kon,[](auto i){return isspace(i);})))?"medzera OK\n":"medzera zle\n");
*/
/*
    //eratostenovo sito
    //list ideálny ak budeme meniť pole, počet prvokv, pridávanie, odoberanie atd.//nevýhoda nedá sa indexovať musí prejsť každý prvok na nájdenie daného prvku
    const int pocet=100000;
    std::forward_list<int>cisla;
    int i=pocet+1;
    std::generate_n(std::front_inserter(cisla),pocet-1,[&i](){return i--;});//[i]-lebo ju zachycujeme//&-lebo ju aj meníme


    i=2;
    int z=2;
    while(i*i<=pocet)
    {
        while(z*i<=pocet)
        {
            cisla.remove(z*i);
            z++;
        }
        i++;
        z=2;
    }
    i=pocet;
    for(auto i:cisla){std::cout<<i<<" ";}
    cout<<std::endl;
    */
    //nacitajte vetu zistite mnozstvo znakov
    /*char r[100]; //={"Jedna, dva, tri, neviem co styri..."};
    fgets(r,100,stdin);
    int d = strlen(r);
    int i,m;
    m=0;
    char z;
    //std::cin>>z;
    for(z=97;z<123;z++)
    {
        for (i = 0; i < d; i++) {
            if (toupper(r[i]) == (toupper(z))) {
                m++;
            }

        }
        cout << "Pocet znakov " << z << ": " << m << std::endl;
        m=0;
    }*/
    std::map<char,int>pismena;
    string veta="Jedna, dva, tri, neviem co styri";
    for(auto i:veta)
    {
        ++pismena[tolower(i)];
    }
    std::vector<std::pair<char,int>>pocty;
    std::copy(pismena.begin(),pismena.end(),std::back_inserter(pocty));
    std::sort(pocty.begin(),pocty.end(),[](auto i, auto j){return  i.second<j.second;});
    for(auto  i:pocty)
    {
        cout<<i.first<<" "<<i.second<<" krat"<<std::endl;
    }
    auto najviac=std::max_element(pismena.begin(),pismena.end(),[](auto i, auto j){return i.second<j.second;});
    cout<<"Najcastejsie je: "<<najviac->first<<" "<<najviac->second<<" krat.";
    return 0;
}
//pri objekte prikaz ,,virtual ... =0,, tak nútime vščetky podtriedy ju prepísať, zatiaľ čo nemôýe byť vytvorená v rodičovskej triede