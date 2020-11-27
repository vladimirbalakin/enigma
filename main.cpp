#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef std::vector<int> veint;
typedef std::vector<char> vechar;

using namespace std;

struct rotor {
    string cipher = "JGDQOXUSCAMIFRVTPNEWKBLZYH", normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int shift = 0;
    bool needToTurnNexRotor = false;
    string update = "7 February 1941";
    rotor() {}
    rotor(int shift_) {
        shift = shift_;
    }
    int decode(int h) {
        h += shift;
        if (h > 25) {
            needToTurnNexRotor = true;
            h %= 26;
        }
        return int(cipher[h]) - int('A');
    }
};

struct reflector {
    string cipher = "FVPJIAOYEDRZXWGCTKUQSBNMHL", normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char update = 'C';
    reflector() {}
};

vector<rotor> rotors;
vector<string> keys;
reflector refl;
string input;

int main() {
    freopen("enigma.txt", "r", stdin);
    freopen("enigmaOut.txt", "w", stdout);
    rotors.resize(3);
    keys = {"JGDQOXUSCAMIFRVTPNEWKBLZYH", "NTZPSFBOKMWRCJDIVLAEYUXHGQ", "JVIUBHTCDYAKEQZPOSGXNRMWFL"};
    for (int i = 0; i < rotors.size(); i++) {
        rotors[i].cipher = keys[i];
    }
    cout << "Used reflector " << refl.update << '\n';
    for (int i = 0; i < rotors.size(); i++) {
        cout << "Used rotor" << i+1 << " Date Introduced: " << rotors[i].update << '\n';
    }
    freopen("enigma.txt", "a+", stdout);
    cin >> input;
    //cout << input;
    //cout << "done";
    for (char h : input) {
        for (int i = 0; i < rotors.size(); i++) {
            
        }
    }
    return 0;
}
