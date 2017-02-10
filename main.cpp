#include <iostream>
#include <unordered_map>

class solution {
  public:
    int parityOfUint64(uint64_t u64) {
        if (dict.find(u64) == dict.end()) {
            int count = 0;
            uint64_t curr = u64;
            uint8_t n;
            while (curr > 0) {
                n = curr - ((curr >> 8)<<8);
                // std::cout << int(n) << std::endl;
                count += parityOfUint8(n);
                curr = curr >> 8;
            }
            dict[u64] = count;
        }

        for (auto it = dict_impl.begin(); it != dict_impl.end(); ++it)
            std::cout << int(it->first) << ": " << it->second << std::endl;
        
        return dict[u64];
    }

  private:
    int parityOfUint8(uint8_t u8) {
        if (dict_impl.find(u8) == dict_impl.end()) {
            int count = 0;
            uint8_t n = u8;
            while (n > 0) {
                if (n%2 == 1)
                    count++;
                n = n >> 1;
            }
            dict_impl[u8] = count;
        }
        return dict_impl[u8];
    }

  private:
    std::unordered_map<uint64_t,int> dict;
    std::unordered_map<uint8_t,int> dict_impl;
};

int main() {
    // uint64_t num = 0x5677345677773232;
    uint64_t num = 0x1000000100010010;

    solution soln;
    int parity = soln.parityOfUint64(num);
    std::cout << "The number of 1's in " << num << " is\n"
              << parity << std::endl;
}
