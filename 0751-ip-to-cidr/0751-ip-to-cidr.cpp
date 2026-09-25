class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> result;
        uint start = ipToInt(ip);
        uint end = start + n - 1;

        while (start <= end) {
            int bits = 0;
            while (bits < 31 && (start & (1 << bits)) == 0) bits++;
            while (end < start + (1 << bits) - 1) bits--;

            result.push_back(intToCIDR(start, 32 - bits));
            start += 1 << bits;
        }

        return result;
    }

    uint ipToInt(string ip) {
        uint result = 0;

        stringstream ss(ip);
        string section;
        while (getline(ss, section, '.')) {
            result <<= 8;
            result += stoi(section);
        }

        return result;
    }

    string intToCIDR(uint ip, int bits) {
        stringstream ss;

        ss << (ip >> 24) << ".";
        ss << ((ip << 8) >> 24) << ".";
        ss << ((ip << 16) >> 24) << ".";
        ss << ((ip << 24) >> 24);
        ss << "/" << bits;

        return ss.str();
    }
};