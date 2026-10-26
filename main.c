#include <stdio.h>

struct TelemetryPacket{
    unsigned int engine_status : 1;
    unsigned int parachute_deployed :1;
    unsigned int flight_mode : 3;
};

void updateKinematics(double *altitude, double *velocity){
    
    *velocity = *velocity + 9.8;
    *altitude = *altitude + *velocity;
    
}

int main(void){
    
    FILE *log_file;
    
    log_file=fopen("flight_log.csv","w");
    struct TelemetryPacket pkt;
    
    double alt= 0, vel=0;
    
    pkt.engine_status = 1;
    pkt.parachute_deployed =0;
    pkt.flight_mode =1;
    
    fprintf(log_file,"Time(s), Altitude(m), Velocity(m/s)\n");
    
    for(int i = 0; i<5; i++){
        updateKinematics(&alt, &vel);
        printf(" Current Time : %d, Altitude: %.2f, Velocity: %.2f \n", i, alt,vel);
        
        
        fprintf(log_file," %d, %.2f, %.2f\n", i, alt, vel);
        
    }
    
    fclose(log_file);
    
    return 0;
    
}
