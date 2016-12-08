library(tcltk)

data <- read.csv("output_DRanti.csv", header = F)

num.row <- nrow(data)

png(filename = "plot_DRanti.png", height = 800, width = 1000, res = 144)
plot(0,0,type = "n", xlim = c(0,10), ylim = c(0,1), xlab = "grid space d [m]", ylab = "Order Parameter")
for(i in 1:num.row){
	d <- data[i,1]
	Ranti <- data[i,3]
	print(Ranti)
	points(d,Ranti)
}
dev.off()

