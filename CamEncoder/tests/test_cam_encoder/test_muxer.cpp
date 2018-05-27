/**
 * Copyright(C) 2018  Steven Hoving
 *
 * This program is free software : you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see < https://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>
#include <CamEncoder/av_muxer.h>
#include "test_utilities.h"
#include <thread>
#include <chrono>
#include <memory>

av_video_meta create_video_config(const int width, const int height, const int fps)
{
    av_video_meta meta;
    meta.quality = 25;
    meta.bpp = 24;
    meta.width = width;
    meta.height = height;
    meta.fps = {fps, 1};
    //meta.preset = video::preset::ultrafast;  // configure 'almost' realtime video encoding
    //meta.profile = video::profile::baseline; // lets try 264 baseline
    meta.profile = video::profile::high; // lets try 264 baseline
    //meta.tune = video::tune::zerolatency;z
    return meta;
}

std::unique_ptr<av_video> create_video_codec(const av_video_meta &meta, AVCodecID codec_id, AVPixelFormat pixel_format)
{
    av_video_codec video_codec_config;
    video_codec_config.id = codec_id;
    video_codec_config.pixel_format = pixel_format;

    return std::make_unique<av_video>(video_codec_config, meta);
}

void test_muxer(const int width, const int height, const int fps, av_muxer_type muxer_type,
    AVCodecID codec_id = AV_CODEC_ID_H264, AVPixelFormat pixel_format = AV_PIX_FMT_BGR24)
{
    auto config = create_video_config(width, height, fps);

    std::string filename = "test_";

    switch(codec_id)
    {
    case AV_CODEC_ID_H264:
        filename += "h264";
        break;
    case AV_CODEC_ID_CSCD:
        filename += "cscd";
        break;
    }

    switch(muxer_type)
    {
    case av_muxer_type::mkv:
        filename += ".mkv";
        break;
    case av_muxer_type::mp4:
        filename += ".mp4";
        break;
    case av_muxer_type::avi:
        filename += ".avi";
        break;
    }

    av_muxer muxer(filename.c_str(), muxer_type);
    muxer.add_stream(create_video_codec(config, codec_id, pixel_format));
    muxer.open();

    auto frame = create_bmpinfo(config.width, config.height, pixel_format);
    DWORD timestamp = GetTickCount();
    for (int i = 0; i < 100; ++i)
    {
        DWORD ts = GetTickCount() - timestamp;
        muxer.encode_frame(ts, (BITMAPINFOHEADER *)frame);
        fill_bmpinfo(frame, ts / fps, pixel_format);
        double dt = (1.0 / (double)fps) * 1000.0;
        Sleep((DWORD)dt);
    }
    free(frame);
}

TEST(test_muxer, test_create_mkv_muxer)
{
    test_muxer(512, 512, 25, av_muxer_type::mkv);
}

TEST(test_muxer, test_create_mp4_muxer)
{
    test_muxer(512, 512, 25, av_muxer_type::mp4);
}

TEST(test_muxer, test_create_mkv_cam_codec_muxer)
{
    av_log_set_level(AV_LOG_TRACE);
    //test_muxer(512, 512, 25, av_muxer_type::mkv, AV_CODEC_ID_CSCD, AV_PIX_FMT_RGB555LE);
    test_muxer(512, 512, 25, av_muxer_type::avi, AV_CODEC_ID_CSCD, AV_PIX_FMT_BGR24);
    test_muxer(512, 512, 25, av_muxer_type::mkv, AV_CODEC_ID_CSCD, AV_PIX_FMT_BGR24);
    //test_muxer(512, 512, 25, av_muxer_type::mkv, AV_CODEC_ID_CSCD, AV_PIX_FMT_BGR0);
}