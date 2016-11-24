data <- read.csv("output_theta.csv", header = T)
# data.phasediff <- read.csv("output_phasediff.csv", header = T)

t_0 = min(data$time)
t_end = max(data$time)

png(filename = "output_PhaseCurve.png", height = 600, width = 300 * (t_end - t_0), res = 144)
plot(data$time, data$theta_1, type = "l", col = "red", xlab="time", ylab = "phase")
par(new=T)
plot(data$time, data$theta_2, type = "l", col = "blue", xlab="", ylab = "")
#3個体の時
# par(new=T)
# plot(data$time, data$theta_3, type = "l", col = "green", xlab="", ylab = "")
dev.off()

#3個体のときはオフ
png(filename = "output_PhaseDiff.png", height = 600, width = 600, res = 144)
plot(data$time, data$phase_diff, type = "l", xlab="time", ylab="phase difference")
dev.off()