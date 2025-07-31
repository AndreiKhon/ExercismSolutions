
function isallowedchar(ch)
    return in(ch, "0123456789qwertyuiopasdfghjklzxcvbnm")
end

function wordcount(sentence)
    wordLength = 0
    startPos = 1
    dict = Dict{String,Int64}()
    sentence = lowercase(sentence)
    for ch in sentence
        if isallowedchar(ch) || ch == '\'' && wordLength != 0
            wordLength += 1
        else
            if wordLength > 0
                word = sentence[startPos:startPos+wordLength-1]
                if word[end] == '\''
                    word = word[begin:end-1]
                end
                get!(dict, word, 0)
                dict[word] += 1
                startPos += wordLength + 1
                wordLength = 0
            else
                startPos += 1
            end
        end
    end
    if wordLength > 0
        word = sentence[startPos:startPos+wordLength-1]
        if word[end] == '\''
            word = word[begin:end-1]
        end
        get!(dict, word, 0)
        dict[word] += 1
    end
    return dict
end
