class Solution {
public:
    vector<string> validateCoupons(
        vector<string>& code,
        vector<string>& businessLine,
        vector<bool>& isActive
    ) {
        int n = code.size();

        // Business line priority
        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<string, string>> valid; // {businessLine, code}

        for (int i = 0; i < n; i++) {
            // 1. Active check
            if (!isActive[i]) continue;

            // 2. Business line check
            if (priority.find(businessLine[i]) == priority.end())
                continue;

            // 3. Code validation
            if (code[i].empty()) continue;

            bool ok = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            valid.push_back({businessLine[i], code[i]});
        }

        // Custom sort
        sort(valid.begin(), valid.end(),
             [&](const pair<string, string>& a,
                 const pair<string, string>& b) {
                 if (priority[a.first] != priority[b.first])
                     return priority[a.first] < priority[b.first];
                 return a.second < b.second;
             });

        // Extract only codes
        vector<string> result;
        for (auto& p : valid) {
            result.push_back(p.second);
        }

        return result;
    }
};
