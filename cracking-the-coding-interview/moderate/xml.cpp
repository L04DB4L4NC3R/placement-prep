/*
 
17.10 Since XML is very verbose, you are given a way of encoding it where each
tag gets mapped to a pre-defined integer value. The language/grammar is as
follows:
Element
--> Tag Attributes END Children END
Attribute --> Tag Value
END -->
Tag
Value --> some predefined mapping to int
--> string value END
0
For example, the following XML might be converted into the compressed string
below (assuming a mapping of family -> 1, person ->2, firstName ->
3, lastName -> 4, state -> 5).
<family lastName="McDowell" state="CA">
<person firstName="Gayle">Some Message</person>
</family>
Becomes:
1 4 McDowell 5 CA 0 2 3 Gayle 0 Some Message 0 0.
Write code to print the encoded version of an XML element (passed in Element
and Attribute objects).

*/

#include <iostream>
#include <unordered_map>
using namespace std;

void makevaluemap(unordered_map<string, int> &m, string tags[], int vals[], int n) {
	for (int i = 0; i < n; ++i) {
		m[tags[i]] = vals[i];
	}
}

string parsexml(unordered_map<string, int> m, string xml) {
	string s;
	string temp;
	bool quteopen = false;

	for(auto i : xml) {
		switch (i) {

			// beginning case
			case '<':
				s += temp + " ";
				temp = "";
				break;

			// this is for the case of keys
			case ' ':
				if (m[temp] != 0) {
					s += to_string(m[temp]) + " ";
				} else {
					s += temp + " ";
				}
				temp = "";
				break;
				
			// this is for the case of attributes
			case '=':
				s += to_string(m[temp]) + " ";
				temp = "";
				break;

			case '\"':
				// if qute was open
				if (quteopen) {
					s += temp + " ";	
				}

				// balance brackets
				quteopen = !quteopen;
				temp = "";
				break;

			// ending case
			case '>':
				s += "0";
				temp = "";
				break;

			// any other alphanumerics
			default:
				temp += i;
				break;
		}
	}
	return s;
}

int main() {

	// take these from stdin
	string tags[] = {"family", "person", "firstName", "lastName", "state"};
	int vals[] = {1,2,3,4,5};
	string xml="<family lastName=\"McDowell\" state=\"CA\"><person firstName=\"Gayle\">Some Message</person> </family>";

	int n = sizeof(vals)/sizeof(int);
	unordered_map<string, int> m;
	makevaluemap(m, tags, vals, n);
	cout << parsexml(m, xml);
	return 0;
}
