gets.to_i.times do |t|
  data = gets.split[1]
  cur_standing = 0
  friends = 0
  data.each_char.with_index do |v, i|
    if i > cur_standing
      friends += i - cur_standing
      cur_standing = i
    end
    cur_standing += v.to_i
  end
  puts "Case ##{t + 1}: #{friends}"
end
