class PID
{
public:
    double kP = 0.0;
    double kI = 0.0;
    double kD = 0.0;

private:
    double error = 0;
    double prevError = 0;
    double derivative = 0;
    double totalError = 0;
    double prev_value;

public:
    double output = 0;
    bool use_I_clamp = false;
    double I_clamp;
    PID(double KP, double KI, double KD)
    {
        kP = KP;
        kI = KI;
        kD = KD;
    }
    void update(double current_value, double target_value)
    {
        error = current_value - target_value;    // P
        derivative = current_value - prev_value; // D

        if (use_I_clamp)
        { // clamped I
            if (totalError > 0)
            { // if positive
                if (totalError > I_clamp)
                { // if above clamp
                    totalError = I_clamp;
                }
                else
                {
                    totalError += error;
                }
            }
            else
            { // if neg
                if (totalError < -I_clamp)
                { // if below clamp
                    totalError = -I_clamp;
                }
                else
                {
                    totalError += error;
                }
            }
        }
        else
        {                        // normal I
            totalError += error; // I
        }
        // calculate output
        output = (error * kP) + (derivative * kD) + (totalError * kI);
        prevError = error;
        prev_value = current_value;
    } // updates PID output
};
