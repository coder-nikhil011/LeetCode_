class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;
        int i = 0;

        // Ek-ek line banayenge
        while (i < words.size()) {

            vector<string> line;
            int length = 0;

            // Current line mein words add karo
            while (i < words.size()) {

                int newLength = length + words[i].size();

                // Agar first word nahi hai,
                // to uske pehle 1 space bhi chahiye
                if (!line.empty()) {
                    newLength++;
                }

                // Agar maxWidth cross ho gaya
                // to current line fix karo
                if (newLength > maxWidth) {
                    break;
                }

                // Word add karo
                line.push_back(words[i]);
                length = newLength;

                i++;
            }

            // Ab current line ko justify karna
            string currentLine = "";

            // Total words ki length
            int totalWordLength = 0;

            for (string word : line) {
                totalWordLength += word.size();
            }

            // Total spaces jo line mein chahiye
            int spaces = maxWidth - totalWordLength;

            // Number of gaps
            int gaps = line.size() - 1;

            // Last Line
            if (i == words.size() || gaps == 0) {

                for (int j = 0; j < line.size(); j++) {

                    if (j > 0) {
                        currentLine += " ";
                    }

                    currentLine += line[j];
                }

                // Remaining spaces end mein
                while (currentLine.size() < maxWidth) {
                    currentLine += " ";
                }
            }

            //Normal Line
            else {

                // Har gap ko minimum kitne spaces?
                int eachGap = spaces / gaps;

                // Kitne extra spaces bach gaye?
                int extra = spaces % gaps;

                for (int j = 0; j < line.size(); j++) {

                    // Word add karo
                    currentLine += line[j];

                    // Last word ke baad gap nahi hota
                    if (j == line.size() - 1) {
                        break;
                    }

                    // Har gap mein eachGap spaces
                    for (int k = 0; k < eachGap; k++) {
                        currentLine += " ";
                    }

                    // Extra spaces left wale gaps ko
                    if (extra > 0) {
                        currentLine += " ";
                        extra--;
                    }
                }
            }

            // Final line answer mein add karo
            ans.push_back(currentLine);
        }

        return ans;
    }
};