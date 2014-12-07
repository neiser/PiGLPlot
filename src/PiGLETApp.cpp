#include <iostream>
#include <sstream>

#include "PiGLETApp.h"
#include "arch.h"
#include "ConfigManager.h"
//#include "PlotWindow.h"
//#include "ImageWindow.h"
#include <sys/prctl.h>

using namespace std;

void PiGLETApp::Draw(){
       
    // Start with a clear screen
    glClearColor(.1,.1,.1,0);
    glClear( GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );
    glLoadIdentity();
    glLineWidth(3);

    // draw the stuff, 
    // but don't let the config manager interfere
    ConfigManager::I().MutexLock();    
    windowman.Draw();
    ConfigManager::I().MutexUnlock();
       
    // check if there are callbacks from the telnet
    // to be executed
    ConfigManager::I().ExecutePendingCallback();
    ReportGLError();
    
    frames++;
    if(frames == 200) {
        frames_timer.Stop();        
        fps = frames/frames_timer.TimeElapsed();
        cout << " FPS: " << fps << endl;
        frames_timer.Start();        
        frames = 0;
    }
}


void PiGLETApp::Init(){
    prctl(PR_SET_NAME, "PiGLET", 0l, 0l, 0l);
    cout << "Starting PiGLET..." << endl;
    frames_timer.Start();
    frames = 0;
    fps = 25.0; // some guess for initial frames
        
//    for (int i = 0 ; i < 1; i++){
//        stringstream ss;
//        ss << "MyTestRecord" << i;
//        windowman.AddWindow(new PlotWindow(&windowman, ss.str()));
//    }
 //   windowman.AddWindow(new PlotWindow(&windowman, "BEAM:IonChamber"));
//    // Add one extra Image Window
//    ImageWindow* w = new ImageWindow(&windowman, "Webcam");
//    windowman.AddWindow(w);
}
