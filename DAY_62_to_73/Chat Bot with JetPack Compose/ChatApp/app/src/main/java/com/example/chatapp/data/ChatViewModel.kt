
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.example.chatapp.ChatState
import com.example.chatapp.ChatUiEvent
import com.example.chatapp.data.Chat
import com.example.chatapp.data.Model
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import kotlinx.coroutines.launch

class ChatViewModel: ViewModel(){



    private val _chatState = MutableStateFlow(ChatState())
    val chatState = _chatState.asStateFlow()


    fun onEvent(event: ChatUiEvent){

        when(event){
            is ChatUiEvent.SendPrompt -> {
                if(event.prompt.isNotEmpty()){
                    addMessage(event.prompt)
                    getResponse(event.prompt)
                }
            }
            is ChatUiEvent.UpdatePrompt -> {
                _chatState.update {
                    it.copy(prompt = event.newPrompt)
                }
            }
        }

    }


    private fun addMessage(message : String){
        _chatState.update {
            it.copy(
                chatList = it.chatList.toMutableList().apply {
                    add(0,Chat(message,true))
                },
                prompt = "",
            )
        }
    }

    private fun getResponse(prompt:String){
        viewModelScope.launch {
            val chat = Model.getResponse(prompt)
            _chatState.update {
                it.copy(
                    chatList = it.chatList.toMutableList().apply {
                        add(0,chat)
                    }
                )
            }
        }
    }

}

