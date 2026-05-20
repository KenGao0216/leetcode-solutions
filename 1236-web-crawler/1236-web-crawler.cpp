/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    unordered_set<string>vis;
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        string startHostname = getHostname(startUrl);
        dfs(startUrl, startHostname, htmlParser);
        return vector<string>(vis.begin(), vis.end());
    }

    string getHostname(string url){
        int pos = min(url.size(), url.find('/', 7));
        return url.substr(7, pos-7);
    }
    void dfs(string url, string startHostname, HtmlParser htmlParser){
        vis.insert(url);
        for(string nxt: htmlParser.getUrls(url)){
            if(getHostname(nxt) == startHostname && !vis.count(nxt)) dfs(nxt, startHostname, htmlParser);
        }
    }
};