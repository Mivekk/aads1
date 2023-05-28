#include "String.h"
#include "SectionList.h"

// function declarations
bool readSelectors(Block* block);
void readAttributes(Block* block);
void handleCommand(SectionList* sectionList, const String& s);
void readCommands(SectionList* sectionList);
void read(SectionList* sectionList);

void commandOne(SectionList* sectionList, const String& s, const String& s1) {
    int curCount = 0;
    Section* section = sectionList->head;

    for (int i = 0; i < sectionList->size; i++) {
        for (int j = 0; j < T; j++) {
            if (section->blocksArr[j] == nullptr || ++curCount != s1.toInt()) {
                continue;
            }
            
            std::cout << s << " == " << section->blocksArr[j]->selectorList->size << "\n";
            return;
        }

        section = section->prev;
    }
}

void commandTwo(SectionList* sectionList, const String& s, const String& s1) {
    int curCount = 0;
    Section* section = sectionList->head;

    for (int i = 0; i < sectionList->size; i++) {
        for (int j = 0; j < T; j++) {
            if (section->blocksArr[j] == nullptr || ++curCount != s1.toInt()) {
                continue;
            }
                
            std::cout << s << " == " << section->blocksArr[j]->attributeList->size << "\n";
            return;
        }

        section = section->prev;
    }
}

void commandThree(SectionList* sectionList, const String& s, const String& s1, const String& s2) {
    int curCount = 0;
    Section* section = sectionList->head;

    for (int i = 0; i < sectionList->size; i++) {
        for (int j = 0; j < T; j++) {
            if (section->blocksArr[j] == nullptr || ++curCount != s1.toInt()) {
                continue;
            }

            Selector* selector = section->blocksArr[j]->selectorList->head;
            for (int k = 0; k < section->blocksArr[j]->selectorList->size; k++) {
                if (k + 1 == s2.toInt()) {
                    std::cout << s << " == " << selector->name << "\n";
                    return;
                }

                selector = selector->prev;
            }            
        }

        section = section->prev;
    }
}

void commandFour(SectionList* sectionList, const String& s, const String& s1, const String& s2) {
    int curCount = 0;
    Section* section = sectionList->head;

    for (int i = 0; i < sectionList->size; i++) {
        for (int j = 0; j < T; j++) {
            if (section->blocksArr[j] == nullptr || ++curCount != s1.toInt()) {
                continue;
            }

            auto attribute = section->blocksArr[j]->attributeList->find(s2);

            if (attribute) {
                std::cout << s << " == " << attribute->value << "\n";
                return;
            }
        }

        section = section->prev;
    }
}

void commandFive(SectionList* sectionList, const String& s, const String& s1) {
    int result = 0;
    Section* section = sectionList->head;

    for (int i = 0; i < sectionList->size; i++) {
        for (int j = 0; j < T; j++) {
            if (section->blocksArr[j] == nullptr) {
                continue;
            }
                
            auto attribute = section->blocksArr[j]->attributeList->find(s1);

            if (attribute) {
                result++;
            }            
        }

        section = section->prev;
    }

    std::cout << s << " == " << result << "\n";
}

void commandSix(SectionList* sectionList, const String& s, const String& s1) {
    int result = 0;
    Section* section = sectionList->head;

    for (int i = 0; i < sectionList->size; i++) {
        for (int j = 0; j < T; j++) {
            if (section->blocksArr[j] == nullptr) {
                continue;
            }                

            auto selector = section->blocksArr[j]->selectorList->find(s1);

            if (selector) {
                result++;
            }
        }

        section = section->prev;
    }

    std::cout << s << " == " << result << "\n";
}

void commandSeven(SectionList* sectionList, const String& s, const String& s1, const String& s2) {
    String result = "";
    Section* section = sectionList->head;

    for (int i = 0; i < sectionList->size; i++) {
        for (int j = 0; j < T; j++) {
            if (section->blocksArr[j] == nullptr) {
                continue;
            }

            auto selector = section->blocksArr[j]->selectorList->find(s1);

            if (!selector) {
                continue;
            }

            auto attribute = section->blocksArr[j]->attributeList->find(s2);

            if (attribute) {
                result = attribute->value;
            }
        }

        section = section->prev;
    }

    if (result.length() > 0) {
        std::cout << s << " == " << result << "\n";
    }
}

void commandEight(SectionList* sectionList, const String& s, const String& s1) {
    int curCount = 0;
    Section* section = sectionList->head;

    for (int i = 0; i < sectionList->size; i++) {
        for (int j = 0; j < T; j++) {
            if (section->blocksArr[j] == nullptr || ++curCount != s1.toInt()) {
                continue;
            }

            delete section->blocksArr[j];
            section->blocksArr[j] = nullptr;
            section->blocksSize--;

            std::cout << s << " == deleted" << "\n";
            return;
        }

        section = section->prev;
    }
}

void commandNine(SectionList* sectionList, const String& s, const String& s1, const String& s2) {
    int curCount = 0;
    Section* section = sectionList->head;

    for (int i = 0; i < sectionList->size; i++) {
        for (int j = 0; j < T; j++) {
            if (section->blocksArr[j] == nullptr || ++curCount != s1.toInt()) {
                continue;
            }

            auto attribute = section->blocksArr[j]->attributeList->find(s2);

            if (attribute) {
                section->blocksArr[j]->attributeList->remove(attribute);

                if (section->blocksArr[j]->attributeList->size == 0) {
                    delete section->blocksArr[j];
                    section->blocksArr[j] = nullptr;
                    section->blocksSize--;
                }

                std::cout << s << " == deleted" << "\n";
                return;
            }
        }

        section = section->prev;
    }
}

bool readSelectors(Block* block) {
    String s;
    char letter = (char)getchar();

    // return false if it's time to read commands
    while (isspace(letter)) {
        letter = (char)getchar();
        if (letter == '?') {
            // read all of the rest ? signs
            for (int i = 0; i < 3; i++) {
                letter = (char)getchar();
            }
            return false;
        }
    }

    // read selectors
    while (letter != '{') {
        if (letter == ',') {
            s.trim();
            Selector* selector = new Selector(s);
            block->selectorList->add(selector);

            s = "";
            letter = (char)getchar();
            continue;
        }
        // add to selector name
        s += letter;
        letter = (char)getchar();
    }
    s.trim();
    if (s.length() > 0) {
        Selector* selector = new Selector(s);
        block->selectorList->add(selector);
    }

    return true;
}

void readAttributes(Block* block) {
    String s = "";
    char letter = (char)getchar();

    // read attributes and values
    while (letter != '}') {
        if (letter == ':') {
            // check for duplicates
            s.trim();
            Attribute* attribute = block->attributeList->find(s);
            if (attribute == nullptr) {
                attribute = new Attribute;
                block->attributeList->add(attribute);
                attribute->name = s;
            }

            s = "";
            letter = (char)getchar();

            // read attribute value
            while (letter != ';' && letter != '}') {
                s += letter;
                letter = (char)getchar();
            }
            // assign attribute value
;           s.trim();
            attribute->value = s;

            if (letter == '}') {
                break;
            }

            s = "";
            letter = (char)getchar();
            continue;
        }

        s += letter;
        letter = (char)getchar();
    }
}

void handleCommand(SectionList* sectionList, const String& s) {
    if (s == "") {
        return;
    }

    if (s == "****") {
        read(sectionList);
        return;
    }
    else if (s == "?") {
        int result = 0;
        Section* section = sectionList->head;
        for (int i = 0; i < sectionList->size; i++) {
            result += section->blocksSize;

            section = section->prev;
        }
        std::cout << "? == " << result << "\n";
    }
    else {
        String s1 = "";
        int sIdx = 0;
        char letter = s[sIdx];
        if (letter >= '0' && letter <= '9') {
            while (letter >= '0' && letter <= '9') {
                s1 += letter;

                sIdx++;
                letter = s[sIdx];
            }
            // skip ,
            sIdx++;
            if (s[sIdx] == 'A') {
                // number, A
                // skip ,
                sIdx += 2;
                if (s[sIdx] == '?') {
                    commandTwo(sectionList, s, s1);
                }
                else {
                    String s2 = "";
                    for (int i = sIdx; i < s.length(); i++) {
                        s2 += s[i];
                    }
                    commandFour(sectionList, s, s1, s2);
                }
            }
            else if (s[sIdx] == 'S') {
                // number, S
                // skip ,
                sIdx += 2;
                if (s[sIdx] == '?') {
                    commandOne(sectionList, s, s1);
                }
                else {
                    String s2 = "";
                    for (int i = sIdx; i < s.length(); i++) {
                        s2 += s[i];
                    }
                    commandThree(sectionList, s, s1, s2);
                }
            }
            else {
                // number, D
                // skip ,
                sIdx += 2;
                if (s[sIdx] == '*') {
                    commandEight(sectionList, s, s1);
                }
                else {
                    String s2 = "";
                    for (int i = sIdx; i < s.length(); i++) {
                        s2 += s[i];
                    }
                    commandNine(sectionList, s, s1, s2);
                }
            }
        }
        else {
            while (letter != ',') {
                s1 += letter;

                sIdx++;
                letter = s[sIdx];
            }
            // skip ,
            sIdx++;
            if (s[sIdx] == 'A') {
                // selector, A
                commandFive(sectionList, s, s1);
            }
            else if (s[sIdx] == 'S') {
                // selector, S
                commandSix(sectionList, s, s1);
            }
            else {
                // selector, E
                // skip ,
                sIdx += 2;
                String s2 = "";
                for (int i = sIdx; i < s.length(); i++) {
                    s2 += s[i];
                }
                commandSeven(sectionList, s, s1, s2);
            }
        }


    }
}

void readCommands(SectionList* sectionList) {
    char letter = (char)getchar();
    String s;
    
    bool readSpaces = false;
    while (true) {
        if (letter == '\n' || letter == EOF) {
            handleCommand(sectionList, s);

            if (letter == EOF) {
                break;
            }

            s = "";
            readSpaces = false;
            letter = (char)getchar();
        }

        if (!isspace(letter) || readSpaces) {
            readSpaces = true;
            s += letter;
        };

        if (letter == EOF) {
            break;
        }

        letter = (char)getchar();
    }
}

void read(SectionList* sectionList) {
    Section* section = sectionList->tail;
    if (section == nullptr || section->blocksArr[T - 1] != nullptr) {
        section = new Section;
    }

    while (true) {
        Block* block = new Block;

        // if there's no section create first one
        if (sectionList->size == 0) {
            section = new Section;
            sectionList->add(section);
        }

        // assign a block to a section
        // if section has full array create new section
        if (section->blocksArr[T - 1] != nullptr) {
            section = new Section;
            sectionList->add(section);
        }
        section->append(block);

        // if it's time to read commands
        if (!readSelectors(block)) {
            // remove block previously allocated
            section->remove(block);
            delete block;

            readCommands(sectionList);
            break;
        }
        readAttributes(block);

        // delete unused sections
        for (int i = 0; i < sectionList->size; i++) {
            if (section->blocksSize == 0) {
                sectionList->remove(section);
            }
        }
    }
}

int main()
{
    SectionList* sectionList = new SectionList;

    read(sectionList);

    return 0;
}