class MyHashSet {
private:
    static const int SIZE = 1000;
    vector<vector<int>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:

    MyHashSet() {
        table.resize(SIZE);
    }

    void add(int key) {

        int index = hash(key);

        for (int x : table[index]) {
            if (x == key)
                return;
        }

        table[index].push_back(key);
    }

    void remove(int key) {

        int index = hash(key);

        for (int i = 0; i < table[index].size(); i++) {

            if (table[index][i] == key) {
                table[index].erase(table[index].begin() + i);
                return;
            }
        }
    }

    bool contains(int key) {

        int index = hash(key);

        for (int x : table[index]) {

            if (x == key)
                return true;
        }

        return false;
    }
};