#ifndef RBTPRINT_H
#define RBTPRINT_H

#include <algorithm>
#include <string>
#include <vector>
#include "RBTNode.h"

class RBTPrint {
private:
    static std::string GetRepeated(char toRepeat, int numberOfTimes) {
        if (numberOfTimes <= 0) {
            return std::string();
        }

        char* chars = new char[numberOfTimes + 1];
        for (int i = 0; i < numberOfTimes; i++) {
            chars[i] = toRepeat;
        }
        chars[numberOfTimes] = '\0';
        std::string result(chars);
        delete[] chars;
        return result;
    }

    static std::string GetSpaces(int numberOfSpaces) {
        return GetRepeated(' ', numberOfSpaces);
    }

    static void IndentLines(std::vector<std::string>& lines, int numberOfSpaces) {
        if (numberOfSpaces > 0) {
            // Prepend indentation to each line
            std::string indent = GetSpaces(numberOfSpaces);
            for (int i = 0; i < lines.size(); i++) {
                lines[i] = indent + lines[i];
            }
        }
    }

    static std::string NodeToString(RBTNode* node) {
        using namespace std;
        if (node->IsRed()) {
            return "[" + to_string(node->key) + " red]";
        }

        return "[" + to_string(node->key) + " black]";
    }

    static std::vector<std::string> TreeToLines(RBTNode* subtreeRoot) {
        using namespace std;

        if (subtreeRoot == nullptr) {
            return vector<string>();
        }

        // Make a string with the subtreeRoot's key enclosed in brackets
        string rootString = NodeToString(subtreeRoot);
        int rootStrLen = rootString.length();

        // Case 1: subtreeRoot is a leaf
        if (subtreeRoot->left == nullptr && subtreeRoot->right == nullptr) {
            vector<string> lines;
            lines.push_back(rootString);
            return lines;
        }

        // Recursively make line strings for each child
        vector<string> leftLines = TreeToLines(subtreeRoot->left);
        vector<string> rightLines = TreeToLines(subtreeRoot->right);

        int lineCount = max(leftLines.size(), rightLines.size());
        vector<string> allLines;
        allLines.resize(lineCount + 2);

        // Case 2: subtreeRoot has no left child
        if (subtreeRoot->left == nullptr) {
            // Create the first 2 lines, not yet indented
            allLines[0] = rootString;
            allLines[1] = GetSpaces(rootStrLen) + "\\";

            // Find where the right child starts
            int rightChildIndent = (int)rightLines[0].find('[');

            // Goal: Indent lines appropriately so that the parent's right branch 
            // character ('\') matches up with the right child's '['.

            if (rightChildIndent <= rootStrLen) {
                // Indent all lines below
                IndentLines(rightLines, rootStrLen - rightChildIndent);
            }
            else {
                // Indent first 2 lines
                string indent = GetSpaces(rightChildIndent - rootStrLen);
                allLines[0] = indent + allLines[0];
                allLines[1] = indent + allLines[1];
            }

            // Copy rightLines into allLines starting at index 2
            for (size_t i = 0; i < rightLines.size(); i++) {
                allLines[i + 2] = rightLines[i];
            }

            return allLines;
        }

        // Case 3: subtreeRoot has no right child
        if (subtreeRoot->right == nullptr) {
            // Goal: Indent lines appropriately so that the parent's left branch 
            // character ('/') matches up with the left child's ']'.

            // Create the first 2 lines
            string indent = GetSpaces(leftLines[0].find(']'));
            allLines[0] = indent + " " + rootString;
            allLines[1] = indent + "/";

            // Copy leftLines into allLines starting at index 2
            for (size_t i = 0; i < leftLines.size(); i++) {
                allLines[i + 2] = leftLines[i];
            }

            return allLines;
        }

        // Case 4: subtreeRoot has both a left and right child

        // The goal is to have the two child nodes as close to the parent as 
        // possible without overlap on any level.

        // Compute absolute indentation, in number of spaces, needed for right lines
        int indentNeeded = 0;
        if (rightLines.size() > 0) {
            // Indent should at least get the immediate right child to be to the 
            // right of the root
            int left0Len = (int)leftLines[0].length();
            indentNeeded = max(0,
                left0Len + (int)rootString.length() - (int)rightLines[0].find('['));
        }
        for (int i = 0; i < leftLines.size() && i < rightLines.size(); i += 2) {
            // Lines with branches are skipped, so the line of interest has only 
            // nodes. The difference between where the left line ends and the 
            // right line begins should be at least 3 spaces for clarity.
            int rightBegin = (int)rightLines[i].find('[');

            int forThisLine = (int)leftLines[i].length() + 3 - rightBegin;
            indentNeeded = max(indentNeeded, forThisLine);
        }

        // Build final lines in allLines starting at index 2
        string absoluteIndent = GetSpaces(indentNeeded);
        for (size_t i = 0; i < leftLines.size() || i < rightLines.size(); i++) {
            // If no right line, just take the left
            if (i >= rightLines.size()) {
                allLines[2 + i] = leftLines[i];
            }
            else {
                string left = "";
                if (i < leftLines.size()) {
                    left = leftLines[i];
                }
                string right = absoluteIndent + rightLines[i];
                allLines[2 + i] = left + right.substr(left.length());
            }
        }

        // The first 2 lines remain. allLines[2] has the proper string for the 
        // 2 child nodes, and thus can be used to create branches in allLines[1].
        int leftIndex = (int)allLines[2].find(']');
        int rightIndex = (int)allLines[2].rfind('[');
        allLines[1] = GetSpaces(leftIndex) + "/" +
            GetSpaces(rightIndex - leftIndex - 1) + "\\";

        // The space between leftIndex and rightIndex is the space that 
        // subtreeRoot's string should occupy. If rootString is too short, put 
        // underscores on the sides.
        rootStrLen = rightIndex - leftIndex - 1;
        if (rootString.length() < rootStrLen) {
            int difference = rootStrLen - (int)rootString.length();
            string underscores = GetRepeated('_', difference / 2);
            if (difference % 2 == 0) {
                rootString = underscores + rootString + underscores;
            }
            else {
                rootString = underscores + rootString + underscores + "_";
            }
        }
        allLines[0] = GetSpaces(leftIndex + 1) + rootString;

        return allLines;
    }

public:
    static std::string TreeToString(RBTNode* subtreeRoot) {
        if (subtreeRoot == nullptr) {
            return "(empty tree)";
        }

        // First convert the tree to an array of line strings
        std::vector<std::string> lines = RBTPrint::TreeToLines(subtreeRoot);

        // Combine all lines into 1 string
        std::string treeString = lines[0];
        for (int i = 1; i < lines.size(); i++) {
            treeString += ("\n" + lines[i]);
        }
        return treeString;
    }
};

#endif
