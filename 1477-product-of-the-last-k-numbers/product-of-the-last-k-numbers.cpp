class ProductOfNumbers {
public:
    vector<int> arr;

    ProductOfNumbers() {}

    void add(int num) {
        arr.push_back(num);
    }

    int getProduct(int k) {
        int ans = 1;

        for(int i = arr.size() - k; i < arr.size(); i++) {
            ans *= arr[i];
        }

        return ans;
    }
};