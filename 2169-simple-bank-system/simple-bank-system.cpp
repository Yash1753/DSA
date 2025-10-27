class Bank {
    vector<long long> bal;
    int n;

    inline bool valid(int a) const { return a >= 1 && a <= n; }

public:
    Bank(vector<long long>& balance) : bal(balance), n((int)balance.size()) {}

    bool transfer(int account1, int account2, long long money) {
        if (!valid(account1) || !valid(account2)) return false;
        if (bal[account1 - 1] < money) return false;
        bal[account1 - 1] -= money;
        bal[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!valid(account)) return false;
        // If your judge allows only positive amounts, you can guard:
        // if (money <= 0) return false;
        bal[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!valid(account)) return false;
        if (bal[account - 1] < money) return false;
        bal[account - 1] -= money;
        return true;
    }
};