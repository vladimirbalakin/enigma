#include <bits/stdc++.h>
#include <locale>

typedef long long ll;
typedef long double ld;
typedef std::vector<int> veint;
typedef std::vector<char> vechar;

using namespace std;

struct rotor {
    string cipher = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"/*JGDQOXUSCAMIFRVTPNEWKBLZYH*/, normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
        h %= 26;
        return int(cipher[h]);
    }
    int encode(int h) {
        h -= shift;
        if (h > 25) {
            needToTurnNexRotor = true;
            h %= 26;
        }
        if (h < 0) {
          h += normal.size();
        }
        return int(cipher[h]);
    }
};

struct reflector {
    string cipher = "FVPJIAOYEDRZXWGCTKUQSBNMHL", normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char update = 'C';
    reflector() {}
    int decode(int h) {
        if (h > 25) {
            h %= 26;
        }
        return int(cipher[h]);
    }
};

vector<rotor> rotors;
vector<string> keys;
reflector refl;
string input;

int main() {
    locale loc;
    freopen("enigma.txt", "a+", stdout);
    freopen("enigma.txt", "r", stdin);
    freopen("enigmaOut.txt", "w", stdout);
    rotors.resize(3);
    /* keys = {"DMTWSILRUYQNKFEJCAZBPGXOHV", "HQZGPJTMOBLNCIFDYAWVEUSRKX", "UQNTLSZFMREHDPXKIBVYGJCWOA"};
    for (int i = 0; i < rotors.size(); i++) {
        rotors[i].cipher = keys[i];
    }*/
    cout << "Used reflector " << refl.update << '\n';
    for (int i = 0; i < rotors.size(); i++) {
        cout << "Used rotor" << i+1 << "; Date Introduced: " << rotors[i].update << '\n';
    }
    freopen("enigma.txt", "a+", stdout);
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
      input[i] = toupper(input[i], loc);
    }
    //cout << input;
    //cout << "done";
    for (char h : input) {
      /* if (rotors[i].needToTurnNexRotor) {
          rotors[i].needToTurnNexRotor = false;
          if (i < rotors.size() - 1) {
              rotors[i+1].shift++;
          }
      }*/
      if (!('A' <= h && 'Z' >= h)) {
        cout << h;
        continue;
      }
      rotors[0].shift++;
      for (int i = 0; i < rotors.size(); i++) {
          // cout << h << ' ';
          h = rotors[i].decode(h - 'A');
      }
      // cout << h << ' ';
      h = refl.decode(h - 'A');
      for (int i = rotors.size()-1; i > -1; i--) {
          // cout << h << ' ';
          h = rotors[i].encode(h - 'A');
      }
      // cout << " ";
      cout << h;
        // cout << '\n';
    }
    //cout << '\n';
    return 0;
}
