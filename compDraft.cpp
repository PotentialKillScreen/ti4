#include<bits/stdc++.h>
using namespace std;

void FactionsIntoGroups(vector<string> factions, int nGroups){
    int nFactions = factions.size();
    int smallGroup = nFactions/nGroups;
    int nBigGroups = nFactions % nGroups;
    int i = 1; 
    for (;i<nBigGroups + 1; i++){
        cout << "Group " << i << ": ";
        for (int j = 0; j< smallGroup + 1; j++){
            cout << factions.back(); 
            factions.pop_back();
            if (j < smallGroup) {
               cout  << ", ";  
            }
            
        }
        cout << endl;
    }
    while(!factions.empty()){
        cout << "Group " << i << ": ";
        for (int j = 0; j < smallGroup; j++){
            cout << factions.back();
            factions.pop_back();
            if (j < smallGroup-1) {
               cout  << ", ";  
            }
        }
        i++;
        cout << endl;
    }
}


int main(){
    bool exp = true;
    vector<string> names{"Axel A", "Axel W", "Oskar S", "Jesper", "August", "Oskar B"};
    random_device rd;
    mt19937 g(rd());
    shuffle(names.begin(),names.end(),g);
    for(int i = 0; i<names.size();i++){
        cout << "Val " << i+1 << ": " << names[i] << endl;
    }
    for(int i = names.size()-1; i>=0;i--){
        cout << "Val " << names.size()*2 -i << ": " << names[i] << endl;
    }
    for(int i = names.size()-1; i>=0;i--){
        cout << "Val " << names.size()*3-i << ": " << names[i] << endl;
    }
    cout << endl;
    vector<string> factions{};
    vector<string> vanillaFactions ={"Arborec", "Barony of Letnev", "Clan of Saar", "Embers of Muaat", "Emirates of Hacan", "Federation of Sol", "Ghost of Creuss", "L1Z1X Mindnet" ,"Mentak Coalition", "Naalu Collective", "Nekro Virus", "Sardakk N'orr", "Universities of Jol-Nar", "Winnu", "Xxcha Kingdom", "Yin Brotherhood", "Yssaril Tribes"};
    vector<string> expFactions = {"Argent Flight", "Empyrean", "Mahact Gene-Sorcerers", "Naaz-Rokha Alliance", "Nomad", "Titans of UI", "Vuil'Raith Cabal", "Keleres"};
    
    if (exp){
        set_union(vanillaFactions.begin(), vanillaFactions.end(), expFactions.begin(), expFactions.end(), back_inserter(factions));
    }
    else {
        factions = vanillaFactions;
    }
    random_device rd2;
    mt19937 g2(rd2());
    shuffle(factions.begin(),factions.end(),g2);
    
    FactionsIntoGroups(factions, names.size()); 
    return 0;
}


       







