#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// 🔐 SECURITY SYSTEM
string text(int n) {
    stringstream s;
    s << n;
    return s.str();
}

string secure_hash(string input) {
    unsigned long long h = 14695981039346656037ULL;
    const unsigned long long p = 1099511628211ULL;
    for(int i=0; i<input.size(); i++) {
        h ^= input[i];
        h *= p;
    }
    stringstream s;
    s << hex << h;
    return s.str();
}

// 👛 WALLET SYSTEM
struct Wallet {
    string private_key;
    string public_key;
    double balance;
};

// 🧱 NETWORK SETTINGS
const double MAX_SUPPLY = 21000000;
double total_coins = 0;

// 🚀 MAIN APP
int main() {
    srand(time(0));

    cout << "\n\n";
    cout << "╔════════════════════════════════════════╗\n";
    cout << "║          🚀 SULE NETWORK 🪙            ║\n";
    cout << "║       CREATED BY: SULE 👑             ║\n";
    cout << "║    BIGGER & STRONGER THAN BITCOIN     ║\n";
    cout << "║          VERSION: 1.0.0               ║\n";
    cout << "╚════════════════════════════════════════╝\n\n";

    Wallet sule;
    sule.private_key = secure_hash("SULE_2026_SECRET_KEY");
    sule.public_key = secure_hash("SULE_OFFICIAL_WALLET");
    sule.balance = 0;

    cout << "✅ YOUR WALLET ACTIVATED\n";
    cout << "🔑 PUBLIC ADDRESS: " << sule.public_key.substr(0,16) << "...\n";
    cout << "🔒 PRIVATE KEY:   " << sule.private_key.substr(0,16) << "...\n\n";

    cout << "⛏️ MINING BLOCK IN PROGRESS...\n";
    double reward = 50;
    sule.balance += reward;
    total_coins += reward;
    cout << "✅ SUCCESS! +50 SULE COINS EARNED 🎉\n\n";

    Wallet user1;
    user1.public_key = secure_hash("USER_WALLET");
    user1.balance = 0;

    sule.balance -= 15;
    user1.balance += 15;
    cout << "💸 TRANSACTION COMPLETED ✅\n";
    cout << "FROM: SULE\n";
    cout << "TO:   NEW USER\n";
    cout << "AMOUNT: 15 SULE COINS\n\n";

    cout << "╔════════════════════════════════════════╗\n";
    cout << "║ 📊 CURRENT BALANCES                    ║\n";
    cout << "║ 💼 SULE:       " << sule.balance << " SULE COINS        ║\n";
    cout << "║ 💼 USERS:      " << user1.balance << " SULE COINS        ║\n";
    cout << "║ 🪙 TOTAL:      " << total_coins << " / " << MAX_SUPPLY << "   ║\n";
    cout << "╚════════════════════════════════════════╝\n\n";

    cout << "✅ SULE NETWORK APP RUNNING SMOOTHLY! 🚀\n";
    return 0;
}
