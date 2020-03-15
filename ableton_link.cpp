#include "ableton/Link.hpp"
#include "ableton_link.h"

AbletonLink *
ableton_link_new(double bpm)
{
    ableton::Link * link = NULL;
    link = new ableton::Link(bpm);
    return reinterpret_cast<AbletonLink *>(link);
}

void
ableton_link_enable(AbletonLink *link_ptr, bool bEnable)
{
    ableton::Link *link = reinterpret_cast<ableton::Link*>(link_ptr);
    link->enable(bEnable);
}

AbletonLinkClock *
ableton_link_clock(AbletonLink *link_ptr)
{
    ableton::Link *link = reinterpret_cast<ableton::Link*>(link_ptr);
    ableton::Link::Clock clock = link->clock();
    ableton::Link::Clock *clock_ptr = new ableton::Link::Clock(clock);
    return reinterpret_cast<AbletonLinkClock*>(clock_ptr);
}

AbletonLinkSessionState *
ableton_link_capture_app_session_state(AbletonLink *link_ptr)
{
    ableton::Link *link = reinterpret_cast<ableton::Link*>(link_ptr);
    ableton::Link::SessionState state = link->captureAppSessionState();
    ableton::Link::SessionState *state_ptr = new ableton::Link::SessionState(state);
    return reinterpret_cast<AbletonLinkSessionState*>(state_ptr);
}

void
ableton_link_destroy(AbletonLink *link_ptr)
{
    ableton::Link *link = reinterpret_cast<ableton::Link*>(link_ptr);
    delete link;
}

long
ableton_link_clock_micros(AbletonLinkClock *clock_ptr)
{
    ableton::Link::Clock *clock = reinterpret_cast<ableton::Link::Clock*>(clock_ptr);
    return clock->micros().count();
}

double
ableton_link_session_state_tempo(AbletonLinkSessionState *state_ptr)
{
    ableton::Link::SessionState *state = reinterpret_cast<ableton::Link::SessionState*>(state_ptr);
    return state->tempo();
}

void
ableton_link_session_state_set_tempo(AbletonLinkSessionState *state_ptr, double bpm, long at_time)
{
    ableton::Link::SessionState *state = reinterpret_cast<ableton::Link::SessionState*>(state_ptr);
    state->setTempo(bpm, std::chrono::microseconds(at_time));
}

double
ableton_link_session_state_beat_at_time(AbletonLinkSessionState *state_ptr, long time, double quantum)
{
    ableton::Link::SessionState *state = reinterpret_cast<ableton::Link::SessionState*>(state_ptr);
    return state->beatAtTime(std::chrono::microseconds(time), quantum);
}

void
ableton_link_session_state_destroy(AbletonLinkSessionState *state_ptr)
{
    ableton::Link::SessionState *state = reinterpret_cast<ableton::Link::SessionState*>(state_ptr);
    delete state;
}
