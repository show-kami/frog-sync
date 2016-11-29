library(animation)
library(jpeg)
library(tcltk)

num.frogs <- 100 # 考えている個体数
data <- read.csv("output_theta.csv", header = T)
num.timeslice <- nrow(data)
theta <- seq(0, 2*pi, by=0.01)

pb <- txtProgressBar(min = 1, max = num.timeslice, style = 3) # プログレスバーの設定
# プログレスバーについて http://gg-hogehoge.hatenablog.com/entry/2013/08/18/095448

execute <- function(){
	for(i in 1:num.timeslice){
		OrderParaX <- data$OrderPara_drawX[i]
		OrderParaY <- data$OrderPara_drawY[i]
		plot(cos(theta), sin(theta), type = "l", xlim = c(-1,1), ylim = c(-1,1) , xlab = "", ylab = "")
		for(j in 1:num.frogs){
			phase_j <- data[i, 1+j]
			points(cos(phase_j), sin(phase_j) , pch = 16, cex = 3, col = "black")
		}
		points(OrderParaX, OrderParaY, pch = 16, cex = 3, col = "gold")
		setTxtProgressBar(pb, i) 
	}
}

# saveHTML(
# 	{
# 		execute()
# 	}, interval = 0.05, movie.name = "./phase_animation.gif"
# )

saveVideo({
	ani.options(interval = 0.01)
	execute()
},video.name = "anime_phase.mp4", other.opts = "-pix_fmt yuv420p -b 1000k"
)
