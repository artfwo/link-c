#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _AbletonLink AbletonLink;
typedef struct _AbletonLinkClock AbletonLinkClock;
typedef struct _AbletonLinkSessionState AbletonLinkSessionState;

AbletonLink *ableton_link_new(double bpm);
void ableton_link_enable(AbletonLink *link_ptr, bool bEnable);
AbletonLinkClock *ableton_link_clock(AbletonLink *link_ptr);
AbletonLinkSessionState *ableton_link_capture_audio_session_state(AbletonLink *link_ptr);
AbletonLinkSessionState *ableton_link_capture_app_session_state(AbletonLink *link_ptr);
void ableton_link_destroy(AbletonLink *link_ptr);

long ableton_link_clock_micros(AbletonLinkClock *clock_ptr);

double ableton_link_session_state_tempo(AbletonLinkSessionState *state);
void ableton_link_session_state_set_tempo(AbletonLinkSessionState *state, double bpm, long at_time);
double ableton_link_session_state_beat_at_time(AbletonLinkSessionState *state_ptr, long time, double quantum);
void ableton_link_session_state_destroy(AbletonLinkSessionState *state);

#ifdef __cplusplus
} /* extern "C" */
#endif
