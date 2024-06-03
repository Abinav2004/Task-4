
The Kalman Filter has inputs and outputs. The inputs are noisy and sometimes inaccurate measurements. The outputs are less noisy and more accurate estimates. the Kalman Filter estimates system parameters that are not observed or measured. It also used past observation to make estimation

Therefore, Kalman Filter is an algorithm that can estimate observable and unobservable parameters with great accuracy in real-time. Estimates with high accuracy are used to make precise predictions and decisions.

### Linear Kalman Filter ###
The linear Kalman filter is an optimal, recursive algorithm for estimating the state of an object if the estimation system is linear and Gaussian. An estimation system is linear if both the motion model and measurement model are linear.

Linear model means both the models can be expressed in terms of a linear function.

The Gaussian distribution, also known as the normal distribution, is characterized by its bell-shaped curve and is defined by two parameters: the mean (average) and the variance (which measures the spread or uncertainty).
![[Pasted image 20240601101844.png|500]]

The Kalman filter assumes that the system is both linear and Gaussian. This means that the equations describing the system dynamics and the measurements are linear, and the noise affecting these equations is Gaussian.

In the motion model, the process noise represents the uncertainty in how the object's state changes over time. If this noise is Gaussian, it means that the deviations from the predicted state (due to unmodeled dynamics or external disturbances) are normally distributed with a certain mean (usually zero) and variance.

In the measurement model, the measurement noise represents the uncertainty in the observations or sensor readings. Gaussian measurement noise means that the measurement errors are normally distributed around the true value with a certain mean (typically zero) and variance.

one of the reason why Gaussian distribution is mainly used because a gaussian when transformed through a linear function stays gaussian.

**Assumptions:**
- we assume **Zero mean Gaussian noise:** is a specific type of Gaussian (normal) noise where the mean (average) of the noise distribution is zero. This implies that the noise is centered around zero and symmetrically distributed on both sides. It simplifies the analysis and modeling of systems, as the noise does not introduce any bias (systematic error) to the measurements or state estimates.
![[Pasted image 20240601104141.png|500]]
### STEPS INVOLVED IN KALMAN FILTERS ###

![[Pasted image 20240531180845.png|500]]

There are mainly two steps involved in Kalman filter
1. Prediction Step 
2. Estimation Step

We perform a prediction, correct it again we perform a prediction with the previous values correct and it goes on like a loop.
### Initialization Step in Kalman Filters

1. **State Estimate Initialization (x_^)**:
   - The state estimate (x_^) is the initial guess of the system's state before any measurements are taken.
   - It is typically based on prior knowledge or experience with the system.
   - For example, if we are estimating position and velocity, ( x_^0 ) would be initialized with initial position and velocity estimates.

2. **Error Covariance Initialization ( P_0 )**:
   - The error covariance matrix (P_0) represents the uncertainty in the initial state estimate.
   - It is initialized based on the expected uncertainty of the initial state.
   - A larger \( P_0 \) indicates more uncertainty, whereas a smaller \( P_0 \) indicates greater confidence in the initial estimate.
   - If there is no prior information, \( P_0 \) can be initialized as a large value (e.g., a diagonal matrix with large values on the diagonal).
   - example-initial estimates for the speed and position of the car are probably not perfectly accurate give by the speedometer it might contain some noise.

3. **Other Initialization Parameters**:
   - Depending on the application, other parameters such as the process noise covariance ( Q ) and the measurement noise covariance (R) may also need to be initialized.
   - These parameters represent the uncertainties in the process model and measurement model, respectively.
#### Process and Measurement Noise Covariance
- **Process Noise Covariance ( Q )**: Represents the uncertainty in the process model.
- **Measurement Noise Covariance ( R )**: Represents the uncertainty in the measurements.
### Importance of Initialization
- The Kalman filter's performance can be highly sensitive to the initial values.
- Good initialization helps the filter converge faster and provide accurate estimates.
- Poor initialization can lead to incorrect estimates and slow convergence.


Other Parameters are **A** and **H**:

**State Transition Matrix (A)**: Describes how the state evolves from one time step to the next.
![[WhatsApp Image 2024-05-31 at 18.49.38_cfea28a2.jpg|500]]
the values will evolve according to the simple linear dynamical system.

**H(measurement matrix)** is used to describe how the state  x at time t​ should be mapped to the measurements z at time t .It defines the relationship between the state variables and the measurements in a linear system.
 ![[WhatsApp Image 2024-05-31 at 19.33.07_97d68733.jpg|600]]

### Kalman Gain (K_t)###
The Kalman Gain is a key component of the Kalman filter that determines how much the actual measurement should influence the predicted state estimate. It plays a crucial role in blending the predicted state estimate with the actual measurement to obtain an optimal state estimate.

### Role of Kalman Gain

The Kalman Gain combines information from the predicted state estimate and the actual measurement to compute the optimal state estimate. It effectively balances the contributions of the prediction and the measurement based on their respective uncertainties:

- **High Kalman Gain**: If  K_t is large, and the filter will trust the measurement more.
- **Low Kalman Gain**: If K_t is  small, and the filter will rely more on the predicted state.

![[Pasted image 20240601112505.png|600]]
In this example the measurement is trusted more rather that the the prediction because the variance is larger for prediction( widely distributed) whereas the measurement have a smaller variance(narrow distribution) and therefore it will have have stronger impact.

#### Why prediction in important ?####
- **Handling Delays:**
    - In real-time systems, there is often a delay between measurements. The prediction step bridges the gap between these measurements, providing a continuous estimation of the state even when no new data is available.
- **Combining Model and Measurement:**
    - The prediction incorporates the knowledge of how the system behaves (the process model), while the update incorporates actual observations (measurements). Combining these two sources of information helps achieve a more accurate and robust estimate.
### Extended Kalman Filter:###
But in Real-Time cases angular components often involved because the system is moving into some direction so we will have sine cosine functions. These are non-linear functions and thus we can't use linear Kalman filter. Non-linear functions leads to non-gaussian distributions in the output and thus Kalman filter can't be used.
![[Pasted image 20240601145522.png|400]]
![[Pasted image 20240601145918.png|300]] ![[Pasted image 20240601150051.png|300]]

One way to resolve This:
perform local linearization, so basically taking a point and at that point computing the first derivative of this function and fit a line through this non-linear function at the linearization point and  treat it as a linear function.
we use tools like Taylor expansion and Jacobians to perform these operations. Mostly mean is chosen as linearization point.
![[Pasted image 20240601151445.png|400]]
There are errors in this approximation too but the errors depend on certain parameters like distance between the non-linear function and the approximated linear function, if they are close the error is less and if they are spaced apart error is large. It also depends on the uncertainty of the input.
## TYPES OF KALMAN FILTER ##
![[Pasted image 20240531201101.png]]

The Extended Kalman Filter (EKF) is used when the state transition and measurement models are non-linear in nature.
Kalman filter is also used in sensor fusion where multiple sensor measurements is fed and more accurate data can be obtained