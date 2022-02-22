#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include"mapa.h"

using std::cout;
using std::string;
using std::make_pair;
using std::pair;


int main() {
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
    cout<<"Najcastejsie je:"<<najviac->first<<" "<<najviac->second<<" krat."
    //

    std::vector<std::pair<string,int>> poctyTried;
    std::copy(slova.begin(),slova.end(),std::back_inserter(poctyTried));
    std::sort(poctyTried.begin(),poctyTried.end(),[](auto i, auto j){return  i.second<j.second;});
    for(auto i: poctyTried)
    {
        cout<<i.second<<" "<<i.first<<std::endl;
    }
    return 0;
}
