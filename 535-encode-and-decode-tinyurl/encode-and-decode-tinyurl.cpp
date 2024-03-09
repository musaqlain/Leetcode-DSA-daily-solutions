class Solution {
public:
    unordered_map<string, string> encodeMp; // longUrl
    unordered_map<string, string> decodeMp; // shortUrl
    string service = "http://tinyurl.com/";

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (encodeMp.find(longUrl) == encodeMp.end()) {
            string shortUrl = service + to_string(encodeMp.size() + 1);
            encodeMp[longUrl] = shortUrl;
            decodeMp[shortUrl] = longUrl;
        }
        return encodeMp[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) { return decodeMp[shortUrl]; }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));