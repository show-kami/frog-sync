library(tcltk)

data <- read.csv("output_theta.csv", header = T)
data.raster <- read.csv("output_thetaForRasterPlot.csv", header = T)

num.frogs <- 100 # 考えている個体数
t_0 = min(data$time)
t_end = max(data$time)


# 各個体の位相の正弦関数の時間変化
# png(filename = "plot_PhaseCurve.png", height = 600, width = 300 * (t_end - t_0), res = 144)
# plot(data$time, sin(data$theta_0), type = "l", col = "red", xlab="time [s]", ylab = "phase")
# if (num >= 2){
# 	par(new=T)
# 	plot(data$time, sin(data$theta_1), type = "l", col = "blue", xlab="", ylab = "")
# }
# if (num >= 3){
# 	par(new=T)
# 	plot(data$time, sin(data$theta_2), type = "l", col = "green", xlab="", ylab = "")
# }
# dev.off()

# 各個体間の位相差の時間変化
# span.time <- c(t_0, t_end)
# span.phase <- c(0, 2*pi)
# png(filename = "plot_PhaseTimeChange.png", height = 1000, width = 1000, res = 144)
# if (num == 2){
# 	plot(data$time, data$PhaseDifference.0_1., type = "l", lty = "solid", xlab="time [s]", ylab="phase difference", xlim = span.time, ylim = span.phase, yaxp = c(span.phase, 4))
# }
# if (num == 3){
# 	par(new=T)
# 	plot(data$time, data$PhaseDifference.0_2., type = "l", lty = "dashed", xlab="", ylab="", xlim = span.time, ylim = span.phase ,yaxp = c(span.phase, 4))
# 	par(new=T)
# 	plot(data$time, data$PhaseDifference.1_2., type = "l", lty = "dotted", xlab="", ylab="", xlim = span.time, ylim = span.phase ,yaxp = c(span.phase, 4))
# }
# dev.off()

# ラスタープロット
pb <- txtProgressBar(min = 1, max = num.frogs - 1, style = 3)
png(filename = "plot_rasterplot.png", height = 300 + 20 * num.frogs, width = 300 * (t_end - t_0), res = 144)
plot(as.matrix(data.raster[1]), as.matrix(data.raster[2]), pch=15, xlim=c(t_0, t_end), ylim=c(0, num.frogs), xlab="time [s]", ylab="Frog No.")
for(i in 1:num.frogs-1){
	time <- as.matrix(data.raster[1])
	raster <- as.matrix(data.raster[i+2])
	par(new = T)
	plot(time, raster, pch=15, xlim=c(t_0, t_end), ylim=c(0, num.frogs), xlab="", ylab="")
	setTxtProgressBar(pb, i) 
}
dev.off()
