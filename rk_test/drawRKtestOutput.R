data <- read.csv("output_test.csv")

x_0 = min(data$x)
x_end = max(data$x)
y_0 = min(c(min(data$y1),min(data$y2)))
y_end = max(c(max(data$y1), max(data$y2)))

plot(data$x, data$y1, col="blue", xlim=c(x_0,x_end),ylim=c(y_0, y_end))
par(new=T)
plot(data$x, data$y2, col="red",xlim=c(x_0,x_end),ylim=c(y_0, y_end))

x_theo = seq(x_0,x_end, by=0.001)
# 問題5-2-(1)
y1_theo = (3*exp(x_theo) + exp(-3*x_theo))/4
y2_theo = (exp(x_theo) - exp(-3*x_theo)) * 3/4

# 問題5-2-(2)
# y1_theo = -2 * exp(-x_theo) * sin(x_theo)
# y2_theo = exp(-x_theo) * (sin(x_theo) + cos(x_theo))

par(new=T)
plot(x_theo, y1_theo, type="l", col="blue", xlim=c(x_0,x_end),ylim=c(y_0, y_end))
par(new=T)
plot(x_theo, y2_theo, type="l", col="red", xlim=c(x_0,x_end),ylim=c(y_0, y_end))