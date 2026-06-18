void start();
int select_menu();
void typing(int);
double calculate_accurate(int);
int result(int,int);
void print_record();

char str[100][100][1000] = { {
    "hesitate", "corporate", "destination", "gravity",
    "agriculture", "desperate", "thrive", "regulate",
    "pupil", "inspire", "revenue", "swamp", "equator",
    "enlist", "transplant", "oppress", "accommodate",
    "radioactive", "predominant", "breathtaking",
    "proportion", "preoccupation", "*"}/*단어*/, {
    "A big fish in a small pond", /*"It never rains but it pours",
    "A bad workman blames his tools", "Every dog has his day",
    "Every cloud has a silver lining", "Familiarity breeds contempt",
    "The early bird catches the worm", "A sound mind in a sound body",
    "Sleep is better than medicine", "There’s no place like home", 
    "Better late than never", "Actions speak louder than words",
    "Lovers are fools", "A watched pot never boils",
    "You can’t have your cake and eat it too",*/ "*"}/*문장*/, {
    "Shame is about who we are, and guilt is about our behaviors.",
    "We feel guilty when we hold up something we’ve done or failed",
    "to do against the kind of person we want to be.",
    "It’s an uncomfortable feeling, but one that’s helpful.",
    "When we apologize for something we’ve done, make amends to others,",
    "or change a behavior that we don’t feel good about, guilt is most often the motivator.",
    "Guilt is just as powerful as shame,", "*"}/*장문*/ 
};
char input[100][1000] = {""};
struct record_type/*저장용 구조체*/ {
    double time;
    double accurate;
    char type[100];
};
struct record_type record[1000] = {0,0};
int total_tried = 0;
