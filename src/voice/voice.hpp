

/*
void t() {
    SDL_AudioStream *capture_stream;
    SDL_AudioDeviceID capture_device = 0;
    const SDL_AudioSpec audio_spec = {SDL_AUDIO_S16LE, 1, 8000};

    capture_device = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_RECORDING, &audio_spec);

    capture_stream = SDL_CreateAudioStream(&audio_spec, &audio_spec);

    if (SDL_GetAudioStreamAvailable(capture_stream) > 100) {
        SDL_GetAudioStreamData(capture_stream, scratch_area + (extra / sizeof(Uint64)), max_datagram - extra);
    }
}
*/
