class MyHashMap {
private:
    static const int SIZE = 1000;

    vector<vector<pair<int, int>>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:

    MyHashMap() {
        table.resize(SIZE);
    }
    void put(int key, int value) {

        int index = hash(key);
        for (auto &p : table[index]) {

            if (p.first == key) {
                p.second = value;   
                return;
            }
        }
        table[index].push_back({key, value});
    }

    int get(int key) {
        int index = hash(key);
        for (auto &p : table[index]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    void remove(int key) {

        int index = hash(key);

        for (int i = 0; i < table[index].size(); i++) {

            if (table[index][i].first == key) {

                table[index].erase(
                    table[index].begin() + i
                );

                return;
            }
        }
    }
};