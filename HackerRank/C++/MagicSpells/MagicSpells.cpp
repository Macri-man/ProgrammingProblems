#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


class Spell {
private:
    string scrollName;
public:
    Spell() : scrollName("") {}
    Spell(string name) : scrollName(name) {}
    virtual ~Spell() {}
    string revealScrollName() const {
        return scrollName;
    }
};

class Fireball : public Spell {
private:
    int power;
public:
    Fireball(int power) : power(power) {}
    void revealFirepower() const {
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell {
private:
    int power;
public:
    Frostbite(int power) : power(power) {}
    void revealFrostpower() const {
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm : public Spell {
private:
    int power;
public:
    Thunderstorm(int power) : power(power) {}
    void revealThunderpower() const {
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell {
private:
    int power;
public:
    Waterbolt(int power) : power(power) {}
    void revealWaterpower() const {
        cout << "Waterbolt: " << power << endl;
    }
};

class SpellJournal {
public:
    static string journal;
};
string SpellJournal::journal = "";

int longestCommonSubsequence(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                
    return dp[m][n];
}

void counterspell(Spell* spell) {
    if (Fireball* fb = dynamic_cast<Fireball*>(spell)) {
        fb->revealFirepower();
    } else if (Frostbite* fr = dynamic_cast<Frostbite*>(spell)) {
        fr->revealFrostpower();
    } else if (Thunderstorm* ts = dynamic_cast<Thunderstorm*>(spell)) {
        ts->revealThunderpower();
    } else if (Waterbolt* wb = dynamic_cast<Waterbolt*>(spell)) {
        wb->revealWaterpower();
    } else {
        cout << longestCommonSubsequence(spell->revealScrollName(), SpellJournal::journal) << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string type;
        int power;
        cin >> type >> power;
        
        Spell* spell = nullptr;
        if (type == "fire") {
            spell = new Fireball(power);
        } else if (type == "frost") {
            spell = new Frostbite(power);
        } else if (type == "water") {
            spell = new Waterbolt(power);
        } else if (type == "thunder") {
            spell = new Thunderstorm(power);
        } else {
            string journal;
            cin >> journal;
            spell = new Spell(type);
            SpellJournal::journal = journal;
        }

        counterspell(spell);
        delete spell;
    }
    return 0;
}