void start();
int select_menu();
void typing(int);
double calculate_accurate(int);

char str[100][100][1000] = { {
    "hesitate", "corporate", "destination", "gravity",
    "agriculture", "desperate", "thrive", "regulate",
    "pupil", "inspire", "revenue", "swamp", "equator",
    "enlist", "transplant", "oppress", "accommodate",
    "radioactive", "predominant", "breathtaking",
    "proportion", "preoccupation", "*"}, {
    "apple", "banana", "*"} };
char input[100][1000] = {""};
struct record_type {
    double time;
    double accurate;
};
