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
ableton_link_enable(AbletonLink *link_ref, bool enable)
{
    ableton::Link *link = reinterpret_cast<ableton::Link*>(link_ref);
    link->enable(enable);
}

bool
ableton_link_is_start_stop_sync_enabled(AbletonLink *link_ref)
{
    ableton::Link *link = reinterpret_cast<ableton::Link*>(link_ref);
    return link->isStartStopSyncEnabled();
}

void
ableton_link_enable_start_stop_sync(AbletonLink *link_ref, bool enable)
{
    ableton::Link *link = reinterpret_cast<ableton::Link*>(link_ref);
    link->enableStartStopSync(enable);
}

AbletonLinkClock *
ableton_link_clock(AbletonLink *link_ref)
{
    ableton::Link *link = reinterpret_cast<ableton::Link*>(link_ref);
    ableton::Link::Clock clock = link->clock();
    ableton::Link::Clock *clock_ref = new ableton::Link::Clock(clock);
    return reinterpret_cast<AbletonLinkClock*>(clock_ref);
}

AbletonLinkSessionState *
ableton_link_capture_audio_session_state(AbletonLink *link_ref)
{
    ableton::Link *link = reinterpret_cast<ableton::Link*>(link_ref);
    ableton::Link::SessionState state = link->captureAudioSessionState();
    ableton::Link::SessionState *state_ref = new ableton::Link::SessionState(state);
    return reinterpret_cast<AbletonLinkSessionState*>(state_ref);
}

void
ableton_link_commit_audio_session_state(AbletonLink *link_ref, AbletonLinkSessionState *state_ref)
{
    ableton::Link *link = reinterpret_cast<ableton::Link*>(link_ref);
    ableton::Link::SessionState *state = reinterpret_cast<ableton::Link::SessionState*>(state_ref);
    link->commitAudioSessionState(*state);
}

AbletonLinkSessionState *
ableton_link_capture_app_session_state(AbletonLink *link_ref)
{
    ableton::Link *link = reinterpret_cast<ableton::Link*>(link_ref);
    ableton::Link::SessionState state = link->captureAppSessionState();
    ableton::Link::SessionState *state_ref = new ableton::Link::SessionState(state);
    return reinterpret_cast<AbletonLinkSessionState*>(state_ref);
}

void
ableton_link_commit_app_session_state(AbletonLink *link_ref, AbletonLinkSessionState *state_ref)
{
    ableton::Link *link = reinterpret_cast<ableton::Link*>(link_ref);
    ableton::Link::SessionState *state = reinterpret_cast<ableton::Link::SessionState*>(state_ref);
    link->commitAppSessionState(*state);
}

void
ableton_link_destroy(AbletonLink *link_ref)
{
    ableton::Link *link = reinterpret_cast<ableton::Link*>(link_ref);
    delete link;
}

uint64_t
ableton_link_clock_micros(AbletonLinkClock *clock_ref)
{
    ableton::Link::Clock *clock = reinterpret_cast<ableton::Link::Clock*>(clock_ref);
    return clock->micros().count();
}

double
ableton_link_session_state_tempo(AbletonLinkSessionState *state_ref)
{
    ableton::Link::SessionState *state = reinterpret_cast<ableton::Link::SessionState*>(state_ref);
    return state->tempo();
}

void
ableton_link_session_state_set_tempo(AbletonLinkSessionState *state_ref, double bpm, uint64_t at_time)
{
    ableton::Link::SessionState *state = reinterpret_cast<ableton::Link::SessionState*>(state_ref);
    state->setTempo(bpm, std::chrono::microseconds(at_time));
}

double
ableton_link_session_state_beat_at_time(AbletonLinkSessionState *state_ref, uint64_t time, double quantum)
{
    ableton::Link::SessionState *state = reinterpret_cast<ableton::Link::SessionState*>(state_ref);
    return state->beatAtTime(std::chrono::microseconds(time), quantum);
}

void
ableton_link_session_state_set_is_playing(AbletonLinkSessionState *state_ref, bool is_playing, uint64_t time)
{
    ableton::Link::SessionState *state = reinterpret_cast<ableton::Link::SessionState*>(state_ref);
    state->setIsPlaying(is_playing, std::chrono::microseconds(time));
}

bool
ableton_link_session_state_is_playing(AbletonLinkSessionState *state_ref)
{
    ableton::Link::SessionState *state = reinterpret_cast<ableton::Link::SessionState*>(state_ref);
    return state->isPlaying();
}

void
ableton_link_session_state_request_beat_at_start_playing_time(AbletonLinkSessionState *state_ref, double beat, double quantum)
{
    ableton::Link::SessionState *state = reinterpret_cast<ableton::Link::SessionState*>(state_ref);
    state->requestBeatAtStartPlayingTime(beat, quantum);
}

void
ableton_link_session_state_destroy(AbletonLinkSessionState *state_ref)
{
    ableton::Link::SessionState *state = reinterpret_cast<ableton::Link::SessionState*>(state_ref);
    delete state;
}
