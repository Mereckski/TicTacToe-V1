#ifndef ENGINE_H
#define ENGINE_H


class engine
{
    public:
        engine();
        void setup();
        virtual ~engine();
    //protected:
    private:

        struct Board{
            char **grid;
            int *player;
            int turn;
            int total_turns;
        };

        void printGrid(Board * game);
        void checkTurn(Board * game);
        void turn(Board * game);
        bool checkSpace(Board * game, int x, int y);
        void updateGrid(Board * game, int x, int y);
        bool winCheck(Board * game);
        void closeGame(Board * game);

};

#endif // ENGINE_H
