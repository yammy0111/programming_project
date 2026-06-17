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
    "proportion", "preoccupation", "*"}/*단어*/, {
    "I'm example", "Me too", "*"}/*문장*/, {
    "I am long sentense", "*"}/*장문*/ 
};
char input[100][1000] = {""};
struct record_type/*저장용 구조체*/ {
    double time;
    double accurate;
};
struct record_type record[1000] = {0,0};
int total_tried = 0;
