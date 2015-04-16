gets.to_i.times do |t|
  _diners = gets.to_i
  data = Hash.new(0)
  gets.split.each { |v| data[v.to_i] += 1 }
  pancakes = data.keys.sort.reverse
  min = pancakes.first
  (1..pancakes.first - 1).each do |max|
    minutes = 0
    progress = data.dup
    (max + 1..pancakes.first).reverse_each do |p|
      plate_count = progress[p]
      progress[max] += plate_count
      progress[p - max] += plate_count
      progress[p] = 0
      minutes += plate_count
    end
    minutes += max
    min = minutes if minutes < min
  end
  puts "Case ##{t + 1}: #{min}"
end
