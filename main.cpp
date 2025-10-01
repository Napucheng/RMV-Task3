#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    cout << "=== 详细FFmpeg检查 ===" << endl;
    
    // 检查OpenCV构建信息
    string buildInfo = getBuildInformation();
    cout << "OpenCV版本: " << CV_VERSION << endl;
    
    // 搜索FFmpeg相关信息
    size_t ffmpegPos = buildInfo.find("FFMPEG");
    if (ffmpegPos != string::npos) {
        cout << "\n找到FFmpeg相关信息:" << endl;
        size_t endPos = buildInfo.find("\n", ffmpegPos);
        cout << buildInfo.substr(ffmpegPos, endPos - ffmpegPos) << endl;
    } else {
        cout << "\n在OpenCV构建信息中未找到FFmpeg" << endl;
    }
    
    // 检查Video I/O部分
    size_t videoIOPos = buildInfo.find("Video I/O:");
    if (videoIOPos != string::npos) {
        cout << "\nVideo I/O支持:" << endl;
        size_t endPos = buildInfo.find("\n", videoIOPos);
        string videoIO = buildInfo.substr(videoIOPos, endPos - videoIOPos);
        cout << videoIO << endl;
    }
    
    // 尝试列出所有可用的后端
    cout << "\n尝试打开视频文件..." << endl;
    string videoPath = "projectile_video.mp4";
    VideoCapture cap(videoPath);
    
    if (cap.isOpened()) {
        cout << "✓ 视频文件可以打开（使用系统默认后端）" << endl;
        
        // 获取视频信息
        Mat frame;
        if (cap.read(frame)) {
            cout << "✓ 成功读取帧: " << frame.cols << " x " << frame.rows << endl;
            cout << "说明：视频编解码器工作正常" << endl;
        }
        cap.release();
    } else {
        cout << "✗ 无法打开视频文件" << endl;
    }
    
    return 0;
}