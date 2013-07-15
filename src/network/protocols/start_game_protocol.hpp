#ifndef START_GAME_PROTOCOL_HPP
#define START_GAME_PROTOCOL_HPP

#include "network/protocol.hpp"
#include <map>

class GameSetup;
class NetworkPlayerProfile;

class StartGameProtocol : public Protocol
{
    protected:
        enum STATE { NONE, LOADING, READY };
        std::map<NetworkPlayerProfile*, STATE> m_player_states;

        GameSetup* m_game_setup;
        bool* m_ready; //!< Set to true when the game can start
        int m_ready_count;
        double m_sending_time;

        STATE m_state;

    public:
        StartGameProtocol(GameSetup* game_setup);
        virtual ~StartGameProtocol();

        virtual void notifyEvent(Event* event);
        virtual void setup();
        virtual void update();

        void ready();
        void onReadyChange(bool* start);

};

#endif // START_GAME_PROTOCOL_HPP
