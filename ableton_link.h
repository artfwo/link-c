#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _AbletonLink AbletonLink;
typedef struct _AbletonLinkClock AbletonLinkClock;
typedef struct _AbletonLinkSessionState AbletonLinkSessionState;

AbletonLink *ableton_link_new(double bpm);
void ableton_link_enable(AbletonLink *link_ref, bool enable);
bool ableton_link_is_start_stop_sync_enabled(AbletonLink *link_ref);
void ableton_link_enable_start_stop_sync(AbletonLink *link_ref, bool enable);
AbletonLinkClock *ableton_link_clock(AbletonLink *link_ref);
AbletonLinkSessionState *ableton_link_capture_audio_session_state(AbletonLink *link_ref);
void ableton_link_commit_audio_session_state(AbletonLink *link_ref, AbletonLinkSessionState *state_ref);
AbletonLinkSessionState *ableton_link_capture_app_session_state(AbletonLink *link_ref);
void ableton_link_commit_app_session_state(AbletonLink *link_ref, AbletonLinkSessionState *state_ref);
void ableton_link_destroy(AbletonLink *link_ref);

uint64_t ableton_link_clock_micros(AbletonLinkClock *clock_ref);

double ableton_link_session_state_tempo(AbletonLinkSessionState *state_ref);
void ableton_link_session_state_set_tempo(AbletonLinkSessionState *state_ref, double bpm, uint64_t at_time);
double ableton_link_session_state_beat_at_time(AbletonLinkSessionState *state_ref, uint64_t time, double quantum);
void ableton_link_session_state_set_is_playing(AbletonLinkSessionState *state_ref, bool is_playing, uint64_t time);
bool ableton_link_session_state_is_playing(AbletonLinkSessionState *state_ref);
void ableton_link_session_state_request_beat_at_start_playing_time(AbletonLinkSessionState *state_ref, double beat, double quantum);
void ableton_link_session_state_destroy(AbletonLinkSessionState *state_ref);

#ifdef __cplusplus
} /* extern "C" */
#endif
