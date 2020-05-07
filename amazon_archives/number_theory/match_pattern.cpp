// https://practice.geeksforgeeks.org/problems/match-specific-pattern/1
vector<string> result;
int correct;
vector<string> findMatchedWords(vector<string> dict,
				string pattern)
{
		//Your code here
		result.clear();
		bool diff[pattern.length()];
		for(int j = 0; j < pattern.length() - 1; ++j) {
				if (pattern[j] == pattern[j+1]) {
						diff[j] = false;
				} else {
						diff[j] = true;
				}
		}
		for(auto word : dict) {
				if (word.length() != pattern.length()) {
						continue;
				}
				correct = 0;
				for (int i = 0; i < word.length() - 1; ++i) {

						if (word[i] == word[i+1]) {
								if(!diff[i]) {
										correct++;
								}
								else {
										break;
								}
						} else {
								if(diff[i]) {
										correct++;
								} else {
										break;
								}
						};

				}
				if (correct == word.length() - 1) {
						result.push_back(word);
				}

		}
		return result;
}
